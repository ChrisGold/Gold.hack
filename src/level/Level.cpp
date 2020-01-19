#include "Level.h"
#include "../action/character/Character.h"
#include "../action/character/Player.h"
#include "../resources/Resources.h"
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

    for (int r = 0; r < LEVEL_X_SIZE; r++) {
        for (int y = 0; y < LEVEL_Y_SIZE && r - y >= 0; y++) {
            drawTile(target, resources, r - y, y);
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
    view.setCenter(WorldToScreen(sf::Vector2f(player->position.x * TILE_X_SIZE, player->position.y * TILE_Y_SIZE)));
    view.move(ISOMETRIC_TILE_SIZE / 2, ISOMETRIC_TILE_SIZE / 2);
    view.setSize(ISOMETRIC_TILE_SIZE * 6, ISOMETRIC_TILE_SIZE * 6);
    return view;
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