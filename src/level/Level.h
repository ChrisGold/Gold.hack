#pragma once

#include <SFML/Graphics/RenderTarget.hpp>
#include <vector>

#include "LevelTile.h"
#include "../Constants.h"
#include "../action/Actor.h"
#include "../TickContext.h"
#include "../action/character/Player.h"
#include "../resources/Resources.h"

class Level {
    sf::View getView(sf::RenderTarget &target);
public:

    Level(LevelTile data[14][14], sf::Vector2i entry, sf::Vector2i exit);
    Player *player;

    std::vector<Actor *> npcs;

    void draw(sf::RenderTarget &target, Resources &resources);

    bool tick(TickContext &ctx);

    void enqueue(Action *action);

    LevelTile tiles[LEVEL_X_SIZE][LEVEL_Y_SIZE];
    sf::Vector2i entryPosition;


    sf::Vector2i exitPosition;

    void drawTile(sf::RenderTarget &target, Resources &resources, int x, int y);
};


// Function to convert a screen (view) position to a world position
// WorldX = (ScreenX + 2*ScreenY)/4
// WorldY = (2*ScreenY - ScreenX)/4
sf::Vector2f ScreenToWorld(sf::Vector2f v);

// Function to convert a world position to a screen (view) position
// ScreenX = 2*WorldX - 2*WorldY
// ScreenY = WorldX + WorldY
sf::Vector2f WorldToScreen(sf::Vector2f v);

sf::FloatRect WorldToScreen(sf::FloatRect r);