#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <ctime>
#include <windows.h>
#include "Menu.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <array>
#include <vector>
#include <random>


using namespace sf;
using namespace std;

class temp
{
public:
	void StartPlay(RenderWindow& window)
	{
		Music music;
		music.openFromFile("Sounds/level_theme.ogg");
		music.play();
		music.setLoop(true);
		RectangleShape background1;
		background1.setSize(Vector2f(1200, 800));
		Texture MainMenuTexture1;
		MainMenuTexture1.loadFromFile("Images/city.png");
		background1.setTexture(&MainMenuTexture1);
		Event event;


		class SoundManager
		{
		public:
			SoundBuffer duckBuffer;
			SoundBuffer jumpBuffer;
			SoundBuffer jump2Buffer;
			Sound duckSound;
			Sound jumpSound;
			Sound jump2Sound;
			int gameSpeed = 8;
			bool playerDead = false;
			bool playDeadSound = false;


			SoundManager()
				:duckBuffer(), jumpBuffer(), jump2Buffer(), duckSound(), jumpSound(), jump2Sound()
			{
				duckBuffer.loadFromFile("Sounds/pain_sound.ogg");
				jumpBuffer.loadFromFile("Sounds/jump_sound.ogg");
				jump2Buffer.loadFromFile("Sounds/jump_sound.ogg");

				duckSound.setBuffer(duckBuffer);
				jumpSound.setBuffer(jumpBuffer);
				jump2Sound.setBuffer(jump2Buffer);
			}
		};



		class Obstacle
		{
		public:
			Sprite obstacleSprite;
			FloatRect obstacleBounds{ 0.f, 0.f, 0.f, 0.f };

			Obstacle(Texture& texture)
				:obstacleSprite(), obstacleBounds()
			{
				obstacleSprite.setTexture(texture);
				obstacleSprite.setPosition(Vector2f(1200, (800 - 150.f)));
				obstacleSprite.setScale(Vector2f(2, 2));
			}
		};
		class Obstacles
		{
		public:

			vector<Obstacle> obstacles;
			Vector2f obstaclespos{ 0.f, 0.f };
			Vector2f obstaclesMotion{ 0.f, 0.f };

			array<IntRect, 15> frame;
			FloatRect obstacleBounds;

			Time spawnTimer;
			Time timeTracker;

			Texture obstacleTexture_1;
			Texture obstacleTexture_2;
			Texture obstacleTexture_3;
			int randomNumber{ 0 };

			Obstacles()
				:obstacles(), obstacleTexture_1(), obstacleTexture_2(), timeTracker(), obstacleTexture_3(), spawnTimer(Time::Zero)

			{
				obstacles.reserve(5);

				if (obstacleTexture_1.loadFromFile("images/mash.png"))
				{
					std::cout << "Loaded cactus Image 1" << std::endl;
				}


				if (obstacleTexture_2.loadFromFile("Images/plant.png"))
				{
					std::cout << "Loaded cactus Image 2" << std::endl;
				}

				if (obstacleTexture_3.loadFromFile("Images/punn.png"))
				{
					std::cout << "Loaded cactus Image 3" << std::endl;

				}

			}

			void update(sf::Time& deltaTime)
			{
				spawnTimer += deltaTime;
				int gameSpeed = 8;
				bool playerDead = false;
				bool playDeadSound = false;
				if (spawnTimer.asSeconds() > 0.5f + gameSpeed / 8)
				{
					randomNumber = (rand() % 3) + 1;
					if (randomNumber == 1)
					{
						obstacles.emplace_back(Obstacle(obstacleTexture_1));
					}
					if (randomNumber == 2)
					{
						obstacles.emplace_back(Obstacle(obstacleTexture_2));
					}
					if (randomNumber == 3)
					{
						obstacles.emplace_back(Obstacle(obstacleTexture_2));
					}
					spawnTimer = sf::Time::Zero;
				}

				if (playerDead == false)
				{
					for (int i = 0; i < obstacles.size(); i++)
					{
						obstacles[i].obstacleBounds = obstacles[i].obstacleSprite.getGlobalBounds();
						obstacles[i].obstacleBounds.width -= 10.f;
						obstacles[i].obstacleSprite.move(-1 * gameSpeed, 0.f);
						if (obstacles[i].obstacleSprite.getPosition().x < 50.f)
						{
							std::vector<Obstacle>::iterator obstacleIter = obstacles.begin() + i;
							obstacles.erase(obstacleIter);
						}
					}
				}

				if (playerDead == true)
				{
					for (auto& obstacles : obstacles)
					{
						obstacles.obstacleSprite.move(0.f, 0.f);
					}
				}

			}

			void drawTo(RenderWindow& window)
			{
				for (auto& obstacles : obstacles)
				{
					window.draw(obstacles.obstacleSprite);
				}
			}

			void reset()
			{
				obstacles.erase(obstacles.begin(), obstacles.end());
			}


		};
		class Dino
		{
		public:
			Sprite dino;
			Vector2f dinoPos{ 0.f, 0.f };
			Vector2f dinoMotion{ 0.f, 0.f };
			Texture dinoTex;
			FloatRect dinoBounds;
			SoundManager soundManager;
			array<IntRect, 25> frames;
			Time timeTracker;
			int animationCounter{ 0 };

			Dino()
				:dino(), dinoTex(), soundManager(), timeTracker()
			{
				if (dinoTex.loadFromFile("Images/DinoSprites_0.png"))
				{
					dino.setTexture(dinoTex);
					for (int i = 0; i < 25; i++)
						frames[i] = IntRect(i * 24, 0, 24, 25);
					dino.setTextureRect(frames[0]);
					dinoPos = dino.getPosition();
					dino.setScale(Vector2f(5, 5));

				}
				else
				{
					std::cout << "Error loading the PlayerSprite texture" << std::endl;
				}
			}

			void update(sf::Time& deltaTime, std::vector<Obstacle>& obstacles)
			{
				int gameSpeed = 8;
				bool playerDead = false;
				bool playDeadSound = false;
				dinoPos = dino.getPosition();
				dinoBounds = dino.getGlobalBounds();
				dinoBounds.height -= 15.f; dinoBounds.width -= 5.f;
				timeTracker += deltaTime;
				for (auto& obstacles : obstacles)
				{
					if (dinoBounds.intersects(obstacles.obstacleBounds))
					{
						playerDead = true;
					}
				}



				if (!playerDead)
				{
					walk();
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) == true && dinoPos.y >= 800 - 150.f)
					{
						animationCounter = 0;
						dinoMotion.y = -2.f; dino.setTextureRect(frames[1]);
						soundManager.jumpSound.play();

					}

					if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) == true && 800 - 150.f > dinoMotion.y >= -2.f)
					{
						animationCounter = 0;
						dinoMotion.y = -3.f; dino.setTextureRect(frames[1]);
						soundManager.jump2Sound.play();
					}

					if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && dinoPos.y >= 800 - 150.f)
					{
						animationCounter = 0;
						dinoMotion.y = 0.f; dino.setTextureRect(frames[18]);
						soundManager.duckSound.play();
					}


					if (dinoPos.y < 800 - 150.f)
					{
						dinoMotion.y += 1.f; dino.setTextureRect(frames[1]);
					}

					if (dinoPos.y > 800 - 150.f)
					{
						dino.setPosition(sf::Vector2f(dino.getPosition().x, 800 - 150.f));
						dinoMotion.y = 0.f;

					}

					dino.move(dinoMotion);
				}

			}

			void walk()
			{
				for (int i = 0; i < 11; i++)
					if (animationCounter == (i + 1) * 3)
						dino.setTextureRect(frames[i]);

				if (animationCounter >= 11)
					animationCounter = 0;

				animationCounter++;
			}
			void reset()
			{
				dinoMotion.y = 0; dino.setPosition(sf::Vector2f(dino.getPosition().x, 800 - 50.f));
				dino.setTextureRect(frames[0]);

			}

		};

		class GameState
		{
		public:

			Dino dino;
			Obstacles obstacles;

			sf::Font gameOverFont;
			sf::Text gameOverText;
			sf::Vector2f mousePos{ 0.f, 0.f };

			GameState()
				: dino(), obstacles(), gameOverFont(), gameOverText()
			{

				dino.dino.setPosition(sf::Vector2f(1200 / 2 - 1200 / 4, 800 - 150.f));


			}
			void setMousePos(sf::Vector2i p_mousePos)
			{
				mousePos.x = p_mousePos.x;
				mousePos.y = p_mousePos.y;
			}

			void update(sf::Time deltaTime)
			{
				int gameSpeed = 8;
				bool playerDead = false;
				bool playDeadSound = false;
				if (playerDead == true)
				{

					obstacles.reset();
					dino.reset();

					playerDead = false;
				}
				else
				{

					obstacles.update(deltaTime);
					dino.update(deltaTime, obstacles.obstacles);
				}

			}

			void drawTo(sf::RenderWindow& window)
			{
				int gameSpeed = 8;
				bool playerDead = false;
				bool playDeadSound = false;
				if (playerDead == true)
				{

					obstacles.drawTo(window);
					window.draw(dino.dino);
					window.draw(gameOverText);

				}
				else
				{
					obstacles.drawTo(window);
					window.draw(dino.dino);

				}
			}

		};
		GameState gameState;


		Time deltaTime;
		Clock deltaTimeClock;

		//Music music;
		//music.openFromFile("level_theme.OGG");
		//music.play();
		while (window.isOpen())
		{

			Event event;
			while (window.pollEvent(event))
			{
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::M))
				{
					music.stop();
					if (Keyboard::isKeyPressed(Keyboard::M))
					{
						music.play();
					}
				}

				switch (event.type)
				{
				case Event::Closed:
					window.close();
					break;
				}
			}

			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					window.close();
				gameState.setMousePos(sf::Mouse::getPosition(window));
			}
			deltaTime = deltaTimeClock.restart();

			gameState.update(deltaTime);

			window.clear(sf::Color::White);
			window.draw(background1);
			gameState.drawTo(window);
			window.display();
		}
	}
};

