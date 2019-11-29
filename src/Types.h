#pragma once

#include <memory>

class Game;
typedef Game* GamePtr;

class Level;
typedef Level* LevelPtr;

class Action;
typedef Action *ActionPtr;

class Actor;

typedef Actor *ActorPtr;

enum Direction : char {
    SELF, NORTH, SOUTH, EAST, WEST
};