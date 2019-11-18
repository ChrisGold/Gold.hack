#include "Level.h"
#include "../worldgen/LevelGenerator.h"
#include <SFML/Graphics/RenderTexture.hpp>

void Level::draw(sf::RenderTarget &target, TileSet &tileset) {
    for (int x = 0; x < LEVEL_X_SIZE; x++) {
        for (int y = 0; y < LEVEL_Y_SIZE; y++) {
            LevelTile t = tiles[x][y];
            auto rect = sf::FloatRect(x * TILE_X_SIZE, y * TILE_Y_SIZE, TILE_X_SIZE, TILE_Y_SIZE);
            tileset.render(target, rect, t);
        }
    }
}

Level::Level() {
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

Level::Level(LevelTile data[LEVEL_X_SIZE][LEVEL_Y_SIZE]) {
    for (int x = 0; x < LEVEL_X_SIZE; x++) {
        for (int y = 0; y < LEVEL_Y_SIZE; y++) {
            LevelTile &thisTile = tiles[x][y];
            LevelTile &thatTile = data[x][y];
            thisTile.pass_east = thatTile.pass_east;
            thisTile.pass_north = thatTile.pass_north;
            thisTile.floor_tile = thatTile.floor_tile;
            thisTile.wall_tile = thatTile.wall_tile;
        }
    }
}

std::vector<Level> Level::make() {
    std::vector<Level> levels;
    LevelGenerator lg = LevelGenerator();
    lg.generate();
    Level l = lg.export_level();
    levels.push_back(l);
    return levels;
}
