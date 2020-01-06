#include "Level.h"
#include "../worldgen/LevelGenerator.h"
#include "../action/character/Character.h"
#include "../action/character/Player.h"
#include <SFML/Graphics/RenderTexture.hpp>

void Level::draw(sf::RenderTarget &target, TileSet &tileset, TextureSet &textureset) {
    for (int x = 0; x < LEVEL_X_SIZE; x++) {
        for (int y = 0; y < LEVEL_Y_SIZE; y++) {
            LevelTile t = tiles[x][y];
            auto rect = sf::FloatRect(x * TILE_X_SIZE, y * TILE_Y_SIZE, TILE_X_SIZE, TILE_Y_SIZE);
            tileset.render(target, rect, t);
        }
    }
    textureset.render(target, player->getRect(), player->texture_id);
    for (auto npc : npcs) {
        textureset.render(target, npc->getRect(), npc->texture_id);
    }
}

Level::Level(LevelTile data[LEVEL_X_SIZE][LEVEL_Y_SIZE]) {
    player = new Player("Player", 0, sf::Vector2i(0, 0));
    npcs.push_back(new Character("Aurelian", 0, sf::Vector2i(3, 3)));
    for (int x = 0; x < LEVEL_X_SIZE; x++) {
        for (int y = 0; y < LEVEL_Y_SIZE; y++) {
            tiles[x][y] = data[x][y];
        }
    }
}

std::vector<Level> Level::make() {
    std::vector<Level> levels;
    LevelGenerator lg = LevelGenerator();
    lg.generate();
    auto l = lg.export_level();
    levels.push_back(l);
    return levels;
}

void Level::enqueue(Action *action) {
    player->enqueue(action);
}

bool Level::tick(const TickContext &ctx) {
    auto turn = player->act(ctx);
    if (turn) {
        for (auto npc : npcs) {
            npc->act(ctx);
        }
    }
    return turn;
}
