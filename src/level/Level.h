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
    sf::View getView();
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


};
