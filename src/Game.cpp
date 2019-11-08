#include <sstream>
#include <SFML/Window.hpp>
#include <SFML/Graphics/Color.hpp>

#include "Game.h"

void Game::init()
{
    window.create(sf::VideoMode(800, 600), "Gold.hack");
    change_stage(0);
    tileSet = TileSet::init();
    auto levels = Level::make(); 
}

void Game::loop()
{
    while (window.isOpen())
    {
        window.clear(sf::Color::White);
        
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

void Game::draw_level(){
    Level& level = levels[std::get<int>(stage)];
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