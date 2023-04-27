//
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
//class GameState
//{
//public:
//
//    Dino dino;
//    Obstacles obstacles;
//
//    sf::Font gameOverFont;
//    sf::Text gameOverText;
//    sf::Vector2f mousePos{ 0.f, 0.f };
//
//    GameState()
//        : dino(), obstacles(), gameOverFont(), gameOverText()
//    {
//
//        dino.dino.setPosition(sf::Vector2f(windowSize_x / 2 - windowSize_x / 4, windowSize_y - 150.f));
//
//
//    }
//    void setMousePos(sf::Vector2i p_mousePos)
//    {
//        mousePos.x = p_mousePos.x;
//        mousePos.y = p_mousePos.y;
//    }
//
//    void update(sf::Time deltaTime)
//    {
//
//        if (playerDead == true)
//        {
//
//            obstacles.reset();
//            dino.reset();
//
//            playerDead = false;
//        }
//        else
//        {
//
//            obstacles.update(deltaTime);
//            dino.update(deltaTime, obstacles.obstacles);
//        }
//
//    }
//
//    void drawTo(sf::RenderWindow& window)
//    {
//        if (playerDead == true)
//        {
//
//            obstacles.drawTo(window);
//            window.draw(dino.dino);
//            window.draw(gameOverText);
//
//        }
//        else
//        {
//            obstacles.drawTo(window);
//            window.draw(dino.dino);
//
//        }
//    }
//
//};
