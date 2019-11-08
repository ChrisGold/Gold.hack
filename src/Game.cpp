#include <sstream>
#include <SFML/Window.hpp>

#include "Game.h"

void Game::init()
{
    window.create(sf::VideoMode(800, 600), "Gold.hack");
    change_stage(0);
}

void Game::loop()
{
    while (window.isOpen())
    {
        window.clear();
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.display();
    }
}

void Game::change_stage(GameStage gs){
    window.setTitle(stage_name(gs));
}

std::string stage_name(GameStage stage)
{
    if (stage == MENU)
    {
        return std::string("Gold.hack: Menu");
    }
    else
    {
        std::ostringstream ss;
        ss << "Gold.hack: Level ";
        ss << std::get<int>(stage);
        return ss.str();
    }
}