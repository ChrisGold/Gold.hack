#include "Input.h"

bool isGameAction(Input i) {
    switch (i) {
        case UP:
        case DOWN:
        case LEFT:
        case RIGHT:
        case ACTION_1:
        case ACTION_2:
            return true;
        case SCROLL_LEFT:
        case SCROLL_RIGHT:
            return false;
    }
}