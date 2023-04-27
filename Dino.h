//#include <iostream>
//#include <SFML/Graphics.hpp>
//#include <SFML/System.hpp>
//#include <SFML/Window.hpp>
//#include <SFML/Audio.hpp>
//#include <SFML/Network.hpp>
//#include <vector>
//#include "Menu.h"
//#include "Obstacle.h"
//using namespace sf;
//using namespace std;
//
//
//class Dino
//{
//public:
//    Sprite dino;
//    Vector2f dinoPos{ 0.f, 0.f };
//    Vector2f dinoMotion{ 0.f, 0.f };
//    Texture dinoTex;
//    FloatRect dinoBounds;
//    SoundManager soundManager;
//    array<IntRect, 25> frames;
//    Time timeTracker;
//    int animationCounter{ 0 };
//
//    Dino()
//        :dino(), dinoTex(), soundManager(), timeTracker()
//    {
//        if (dinoTex.loadFromFile("rsrc/Images/PlayerSpriteSheet.png"))
//        {
//            dino.setTexture(dinoTex);
//            for (int i = 0; i < 25; i++)
//                frames[i] = IntRect(i * 24, 0, 24, 25);
//            dino.setTextureRect(frames[0]);
//            dinoPos = dino.getPosition();
//        }
//        else
//        {
//            std::cout << "Error loading the PlayerSprite texture" << std::endl;
//        }
//    }
//
//    void update(sf::Time& deltaTime, std::vector<Obstacle>& obstacles)
//    {
//        dinoPos = dino.getPosition();
//        dinoBounds = dino.getGlobalBounds();
//        dinoBounds.height -= 15.f; dinoBounds.width -= 5.f;
//        timeTracker += deltaTime;
//        for (auto& obstacles : obstacles)
//        {
//            if (dinoBounds.intersects(obstacles.obstacleBounds))
//            {
//                playerDead = true;
//            }
//        }
//
//
//
//        if (!playerDead)
//        {
//            walk();
//            if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) == true && dinoPos.y >= windowSize_y - 150.f)
//            {
//                animationCounter = 0;
//                dinoMotion.y = -5.f; dino.setTextureRect(frames[1]);
//                soundManager.jumpSound.play();
//
//            }
//
//            if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) == true && windowSize_y - 150.f > dinoMotion.y >= -5.f)
//            {
//                animationCounter = 0;
//                dinoMotion.y = -9.f; dino.setTextureRect(frames[1]);
//                soundManager.jump2Sound.play();
//            }
//
//            if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && dinoPos.y >= windowSize_y - 150.f)
//            {
//                animationCounter = 0;
//                dinoMotion.y = 0.f; dino.setTextureRect(frames[18]);
//                soundManager.duckSound.play();
//            }
//
//
//            if (dinoPos.y < windowSize_y - 150.f)
//            {
//                dinoMotion.y += 1.f; dino.setTextureRect(frames[1]);
//            }
//
//            if (dinoPos.y > windowSize_y - 150.f)
//            {
//                dino.setPosition(sf::Vector2f(dino.getPosition().x, windowSize_y - 150.f));
//                dinoMotion.y = 0.f;
//
//            }
//
//            dino.move(dinoMotion);
//        }
//
//    }
//
//    void walk()
//    {
//        for (int i = 0; i < 11; i++)
//            if (animationCounter == (i + 1) * 3)
//                dino.setTextureRect(frames[i]);
//
//        if (animationCounter >= 11)
//            animationCounter = 0;
//
//        animationCounter++;
//    }
//    void reset()
//    {
//        dinoMotion.y = 0; dino.setPosition(sf::Vector2f(dino.getPosition().x, windowSize_y - 50.f));
//        dino.setTextureRect(frames[0]);
//
//    }
//
//};
