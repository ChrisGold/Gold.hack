#pragma once

class Game;

class Resources;

class Inventory;

struct InitContext {
    Game *game;
    Resources *resources;
    Inventory *inventory;
};