#include <ctime>
#include "inventory/Inventory.h"

#pragma once

class Game;

class Level;

/**
 * An encapsulated context of a single Tick in the game.
 */
struct TickContext {
    Game *game;
    Level *level;
    Inventory *playerInventory;
    /**
     * A running counter of ticks, unique to each game.
     */
    const long tick_nr;
    const time_t wall_time;
    float difficulty;
    /**
     * A pointer to the messageQueue displayed in the inventory.
     */
    std::vector<std::string> *messageQueue;

    TickContext(Game *game, Level *level, Inventory *playerInventory, const long tickNr, const time_t wallTime,
                float difficulty)
            : game(game),
              level(level),
              playerInventory(playerInventory),
              tick_nr(tickNr),
              wall_time(wallTime),
              difficulty(difficulty), messageQueue(&playerInventory->messages) {}

    virtual ~TickContext() = default;
};
