#pragma once

#include <SFML/Graphics/Color.hpp>
#include <random>

const int LEVEL_X_SIZE = 16;
const int LEVEL_Y_SIZE = 16;

const int MAZE_X_SIZE = 8;
const int MAZE_Y_SIZE = 8;

const int TILE_X_SIZE = 50;
const int TILE_Y_SIZE = 50;

const int TPS = 20;
const int MS_PER_TICK = 1000 / TPS;

const int BORDER_WIDTH = 25;
const int LEVEL_WIDTH = LEVEL_X_SIZE * TILE_X_SIZE;
const int TOTAL_HEIGHT = LEVEL_Y_SIZE * TILE_Y_SIZE + 2 * BORDER_WIDTH;
const int SIDEBAR_WIDTH = 8 * TILE_X_SIZE;
const int TOTAL_WIDTH = LEVEL_WIDTH + SIDEBAR_WIDTH + 3 * BORDER_WIDTH;

const int VIEWPORT_WIDTH = 400;
const int VIEWPORT_HEIGHT = 400;

const int VOID_ID = 0;
const std::string VOID_NAME = "void";
const std::string EXIT_TILE = "exit";

const std::string FONT_DEFAULT = "LiberationSerif-Regular";
const sf::Color goldenrod = sf::Color(0XDAA250FF);
const sf::Color gold = sf::Color(0xFFD700FF);
const sf::Color light_gray = sf::Color(0XAAAAAAFF);
const sf::Color dark_grey = sf::Color(0X444444FF);

const bool DRAW_WALLS = false;