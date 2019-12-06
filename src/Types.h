#pragma once

#include <memory>

class Game;

typedef std::shared_ptr<Game> GamePtr;

class Level;

typedef std::shared_ptr<Level> LevelPtr;

class Action;
typedef Action *ActionPtr;

class Actor;

typedef Actor *ActorPtr;

enum Direction : char {
    SELF, NORTH, SOUTH, EAST, WEST
};