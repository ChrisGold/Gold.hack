#include "Level.h"
#include "../worldgen/LevelGenerator.h"
#include <SFML/Graphics/RenderTexture.hpp>

void Level::draw(sf::RenderTarget &target, TileSet &tileset, TextureSet &textureset) {
    for (int x = 0; x < LEVEL_X_SIZE; x++) {
        for (int y = 0; y < LEVEL_Y_SIZE; y++) {
            LevelTile t = tiles[x][y];
            auto rect = sf::FloatRect(x * TILE_X_SIZE, y * TILE_Y_SIZE, TILE_X_SIZE, TILE_Y_SIZE);
            tileset.render(target, rect, t);
        }
    }
    auto playerrect = sf::FloatRect(player->position.x * TILE_X_SIZE, player->position.y * TILE_Y_SIZE, TILE_X_SIZE,
                                    TILE_Y_SIZE);
    textureset.render(target, playerrect, player->texture_id);
}

Level::Level(GamePtr gamePtr) : player(new Actor(gamePtr, *this, 0, sf::Vector2i(0, 0))) {
    this->game = gamePtr;
    for (int x = 0; x < LEVEL_X_SIZE; x++) {
        for (int y = 0; y < LEVEL_Y_SIZE; y++) {
            LevelTile &t = tiles[x][y];
            t.pass_east = false;
            t.pass_north = false;
            t.floor_tile = 0;
            t.wall_tile = 0;
        }
    }
}

Level::Level(GamePtr gamePtr, LevelTile data[LEVEL_X_SIZE][LEVEL_Y_SIZE]) : player(
        new Actor(gamePtr, *this, 0, sf::Vector2i(0, 0))) {
    this->game = gamePtr;
    for (int x = 0; x < LEVEL_X_SIZE; x++) {
        for (int y = 0; y < LEVEL_Y_SIZE; y++) {
            tiles[x][y] = data[x][y];
        }
    }
}

std::vector<Level> Level::make(GamePtr gamePtr) {
    std::vector<Level> levels;
    LevelGenerator lg = LevelGenerator();
    lg.generate();
    Level l = lg.export_level(gamePtr);
    levels.push_back(l);
    return levels;
}

void Level::enqueue(ActionPtr action) {
    player->enqueue(std::shared_ptr<Action>(action));
}

bool Level::tick() {
    return player->act();
}
