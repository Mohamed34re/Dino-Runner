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
//class Obstacles
//{
//public:
//
//    vector<Obstacle> obstacles;
//    Vector2f obstaclespos{ 0.f, 0.f };
//    Vector2f obstaclesMotion{ 0.f, 0.f };
//
//    //array<IntRect, 15> frame;
//    FloatRect obstacleBounds;
//
//    Time spawnTimer;
//    Time timeTracker;
//
//    Texture obstacleTexture_1;
//    Texture obstacleTexture_2;
//    Texture obstacleTexture_3;
//    int randomNumber{ 0 };
//
//    Obstacles()
//        :obstacles(), obstacleTexture_1(), obstacleTexture_2(), timeTracker(), obstacleTexture_3(), spawnTimer(Time::Zero)
//
//    {
//        obstacles.reserve(5);
//
//        if (obstacleTexture_1.loadFromFile("rsrc/Images/Cactus1.png"))
//        {
//            std::cout << "Loaded cactus Image 1" << std::endl;
//        }
//
//        if (obstacleTexture_2.loadFromFile("rsrc/Images/Cactus2.png"))
//        {
//            std::cout << "Loaded cactus Image 2" << std::endl;
//        }
//
//        if (obstacleTexture_3.loadFromFile("rsrc/Images/Cactus3.png"))
//        {
//            std::cout << "Loaded cactus Image 3" << std::endl;
//
//        }
//
//    }
//
//    void update(sf::Time& deltaTime)
//    {
//        spawnTimer += deltaTime;
//        if (spawnTimer.asSeconds() > 0.5f + gameSpeed / 8)
//        {
//            randomNumber = (rand() % 3) + 1;
//            if (randomNumber == 1)
//            {
//                obstacles.emplace_back(Obstacle(obstacleTexture_1));
//            }
//            if (randomNumber == 2)
//            {
//                obstacles.emplace_back(Obstacle(obstacleTexture_2));
//            }
//            if (randomNumber == 3)
//            {
//                obstacles.emplace_back(Obstacle(obstacleTexture_2));
//            }
//            spawnTimer = sf::Time::Zero;
//        }
//
//        if (playerDead == false)
//        {
//            for (int i = 0; i < obstacles.size(); i++)
//            {
//                obstacles[i].obstacleBounds = obstacles[i].obstacleSprite.getGlobalBounds();
//                obstacles[i].obstacleBounds.width -= 10.f;
//                obstacles[i].obstacleSprite.move(-1 * gameSpeed, 0.f);
//                if (obstacles[i].obstacleSprite.getPosition().x < 50.f)
//                {
//                    std::vector<Obstacle>::iterator obstacleIter = obstacles.begin() + i;
//                    obstacles.erase(obstacleIter);
//                }
//            }
//        }
//
//        if (playerDead == true)
//        {
//            for (auto& obstacles : obstacles)
//            {
//                obstacles.obstacleSprite.move(0.f, 0.f);
//            }
//        }
//
//    }
//
//    void drawTo(RenderWindow& window)
//    {
//        for (auto& obstacles : obstacles)
//        {
//            window.draw(obstacles.obstacleSprite);
//        }
//    }
//
//    void reset()
//    {
//        obstacles.erase(obstacles.begin(), obstacles.end());
//    }
//
//
//};
