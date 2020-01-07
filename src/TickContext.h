#include <ctime>

#pragma once

class Game;

class Level;

struct TickContext {
    Game *game;
    Level *level;
    const long tick_nr;
    const time_t wall_time;

    TickContext(Game *game, Level *level, const long tickNr, const time_t wallTime) : game(game),
                                                                                      level(level),
                                                                                      tick_nr(tickNr),
                                                                                      wall_time(wallTime) {}

    virtual ~TickContext() = default;
};
