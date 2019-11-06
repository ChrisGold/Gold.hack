#include "Game.h"
#include <SFML/Window.hpp>

void Game::init()
{
    window.create(sf::VideoMode(800, 600), "My window");
}

void Game::loop()
{
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }
    }
}