#pragma once

#include <SFML/Graphics/Color.hpp>

const int LEVEL_X_SIZE = 14;
const int LEVEL_Y_SIZE = 14;

const int TILE_X_SIZE = 50;
const int TILE_Y_SIZE = 50;

const int TPS = 20;
const int MS_PER_TICK = 1000 / TPS;

const int LEVEL_WIDTH = LEVEL_X_SIZE * TILE_X_SIZE;
const int TOTAL_HEIGHT = LEVEL_Y_SIZE * TILE_Y_SIZE;
const int SIDEBAR_WIDTH = 8 * TILE_X_SIZE;
const int TOTAL_WIDTH = LEVEL_WIDTH + SIDEBAR_WIDTH;

const int VOID_ID = 0;
const std::string VOID_NAME = "void";

const std::string FONT_DEFAULT = "LiberationSerif-Regular";
const sf::Color goldenrod = sf::Color(0XDAA250FF);
const sf::Color gold = sf::Color(0xFFD700FF);
const sf::Color light_gray = sf::Color(0XAAAAAAFF);