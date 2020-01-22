#pragma once

enum Input {
    UP, DOWN, LEFT, RIGHT, TURN_UP, TURN_DOWN, TURN_LEFT, TURN_RIGHT, SCROLL_LEFT, SCROLL_RIGHT, ACTION_1, ACTION_2
};

bool isGameAction(Input i);