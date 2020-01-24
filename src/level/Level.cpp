#include "../Game.h"
#include "Level.h"
#include "../action/character/Player.h"
#include <SFML/Graphics/RenderTexture.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

const float ISOMETRIC_TILE_SIZE = measureUnit(TILE_X_SIZE);

void Level::drawTile(sf::RenderTarget &target, Resources &resources, int x, int y) {
    LevelTile t = tiles[x][y];
    auto rect = sf::FloatRect(x * TILE_X_SIZE, y * TILE_Y_SIZE, ISOMETRIC_TILE_SIZE, ISOMETRIC_TILE_SIZE);
    resources.render(target, WorldToScreen(rect), t);
}

void Level::draw(sf::RenderTarget &target, Resources &resources) {
    target.setView(getView(target));

    for (int k = 0; k <= LEVEL_X_SIZE + LEVEL_Y_SIZE - 2; k++) {
        for (int j = 0; j <= k; j++) {
            int i = k - j;
            if (i < LEVEL_Y_SIZE && j < LEVEL_X_SIZE) {
                drawTile(target, resources, i, j);
            }
        }
    }

    resources.render(target, WorldToScreen(player->getRect()), player->texture_id);
    for (auto npc : npcs) {
        resources.render(target, WorldToScreen(npc->getRect()), npc->texture_id);
    }
}

Level::Level(LevelTile data[14][14], sf::Vector2i entry, sf::Vector2i exit) {
    this->entryPosition = entry;
    this->exitPosition = exit;
    player = new Player("Player", 1, entry);
    for (int x = 0; x < LEVEL_X_SIZE; x++) {
        for (int y = 0; y < LEVEL_Y_SIZE; y++) {
            tiles[x][y] = data[x][y];
        }
    }
}

void Level::enqueue(Action *action) {
    player->enqueue(action);
}

bool isNPCDead(const Actor *npc) {
    return !npc->isAlive();
}

bool Level::tick(TickContext &ctx) {
    if (!player->isAlive()) {
        ctx.game->game_over();
        return true;
    }
    auto turn = player->act(ctx);
    if (turn) {
        for (auto npc : npcs) {
            npc->act(ctx);
        }
        npcs.erase(std::remove_if(npcs.begin(), npcs.end(), isNPCDead), npcs.end());
    }
    return turn;
}

sf::View Level::getView(sf::RenderTarget &target) {
    sf::View view{};
    view.setCenter(WorldToScreen(sf::Vector2f(player->position.x * TILE_X_SIZE, player->position.y * TILE_Y_SIZE)));
    view.move(ISOMETRIC_TILE_SIZE / 2, ISOMETRIC_TILE_SIZE / 2);
    view.setSize(ISOMETRIC_TILE_SIZE * 6, ISOMETRIC_TILE_SIZE * 6);
    return view;
}

bool Level::isPositionFree(sf::Vector2i pos) {
    bool freeGround = tiles[pos.x][pos.y].floor_tile != VOID_NAME;
    bool freeSpace =
            std::find_if(npcs.begin(), npcs.end(), [pos](Actor *npc) { return npc->position == pos; }) == npcs.end();
    return freeGround && freeSpace;
}

Actor *Level::at(sf::Vector2i pos) {
    if (pos.x < 0 || pos.y < 0 || pos.x >= LEVEL_X_SIZE || pos.y >= LEVEL_Y_SIZE) {
        return nullptr;
    }
    if (pos == player->position) {
        return player;
    }
    auto it = std::find_if(npcs.begin(), npcs.end(), [pos](Actor *npc) { return npc->position == pos; });
    if (it == npcs.end()) return nullptr;
    else return *it;
}


sf::Vector2f WorldToScreen(sf::Vector2f v) {
    return sf::Vector2f(2.0f * v.x - 2.0f * v.y, v.x + v.y);
}

sf::FloatRect WorldToScreen(sf::FloatRect r) {
    return sf::FloatRect(WorldToScreen(r.getPosition()), sf::Vector2f(ISOMETRIC_TILE_SIZE, ISOMETRIC_TILE_SIZE));
}

sf::Vector2f ScreenToWorld(sf::Vector2f v) {
    return sf::Vector2f((v.x + 2.0f * v.y) / 4.0f, (2.0f * v.y - v.x) / 4.0f);
}

float measureUnit(float distance) {
    auto bottomLeftCorner = WorldToScreen(sf::Vector2f(0, distance));
    auto bottomRightCorner = WorldToScreen(sf::Vector2f(distance, 0));
    return bottomRightCorner.x - bottomLeftCorner.x;
};