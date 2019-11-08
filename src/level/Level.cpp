#include <iostream>
#include "Level.h"

void Level::draw(sf::RenderTarget &target, TileSet& tileset)
{
    for (int x = 0; x < LEVEL_X_SIZE; x++)
    {
        for (int y = 0; y < LEVEL_Y_SIZE; y++)
        {
            LevelTile t = tiles[x][y];
            auto id = t.tile_id;
            auto sprite = tileset.make_sprite(id);
            sprite.setPosition(x * TILE_X_SIZE, y * TILE_Y_SIZE);
            target.draw(sprite);
        }
    }
}

Level::Level()
{
    for (int x = 0; x < LEVEL_X_SIZE; x++)
    {
        for (int y = 0; y < LEVEL_Y_SIZE; y++)
        {
            LevelTile& t = tiles[x][y];
            t.pass_east = true;
            t.pass_north = true;
            t.tile_id = (x + y) % 3;
        }
    }
}

std::vector<Level> Level::make()
{
    std::vector<Level> levels;
    Level l{};
    levels.push_back(l);
    return levels;
}
