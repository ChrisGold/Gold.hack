#include "Level.h"
#include "../action/character/Character.h"
#include "../action/character/Player.h"
#include "../resources/Resources.h"
#include <SFML/Graphics/RenderTexture.hpp>

void Level::draw(sf::RenderTarget &target, Resources &resources) {
    target.setView(getView(target));
    for (int x = 0; x < LEVEL_X_SIZE; x++) {
        for (int y = 0; y < LEVEL_Y_SIZE; y++) {
            LevelTile t = tiles[x][y];
            auto rect = sf::FloatRect(x * TILE_X_SIZE, y * TILE_Y_SIZE, TILE_X_SIZE, TILE_Y_SIZE);
            resources.render(target, rect, t);
        }
    }
    resources.render(target, player->getRect(), player->texture_id);
    for (auto npc : npcs) {
        resources.render(target, npc->getRect(), npc->texture_id);
    }
}

Level::Level(LevelTile data[14][14], sf::Vector2i entry, sf::Vector2i exit, InitContext initContext) : map(
        *initContext.resources, LEVEL_X_SIZE, LEVEL_Y_SIZE, TILE_X_SIZE) {
    this->entryPosition = entry;
    this->exitPosition = exit;
    player = new Player("Player", 1, entry);
    for (int x = 0; x < LEVEL_X_SIZE; x++) {
        for (int y = 0; y < LEVEL_Y_SIZE; y++) {
            tiles[x][y] = data[x][y];
            map.addFloor(x, y, data[x][y].floor_tile);
        }
    }
}

void Level::enqueue(Action *action) {
    player->enqueue(action);
}

bool Level::tick(TickContext &ctx) {
    auto turn = player->act(ctx);
    if (turn) {
        for (auto npc : npcs) {
            npc->act(ctx);
        }
    }
    return turn;
}

sf::View Level::getView(sf::RenderTarget &target) {
    sf::View view{};
    view.setCenter(player->position.x * TILE_X_SIZE, player->position.y * TILE_Y_SIZE);
    view.setSize(VIEWPORT_WIDTH, VIEWPORT_HEIGHT);
    return view;
}
