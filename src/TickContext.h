#include <ctime>
#include "inventory/Inventory.h"

#pragma once

class Game;

class Level;

struct TickContext {
    Game *game;
    Level *level;
    Inventory *playerInventory;
    const long tick_nr;
    const time_t wall_time;

    TickContext(Game *game, Level *level, Inventory *playerInventory, const long tickNr, const time_t wallTime)
            : game(game),
              level(level),
              playerInventory(playerInventory),
              tick_nr(tickNr),
              wall_time(wallTime) {}

    virtual ~TickContext() = default;
};
