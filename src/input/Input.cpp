#include "Input.h"

bool isGameAction(Input i) {
    switch (i) {
        case UP:
        case DOWN:
        case LEFT:
        case RIGHT:
        case TURN_UP:
        case TURN_DOWN:
        case TURN_LEFT:
        case TURN_RIGHT:
        case ACTION_1:
        case ACTION_2:
            return true;
        case SCROLL_LEFT:
        case SCROLL_RIGHT:
            return false;
    }
}