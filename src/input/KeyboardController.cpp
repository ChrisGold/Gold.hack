//
// Created by christian on 27.11.19.
//

#include <iostream>
#include "KeyboardController.h"

KeyboardController::KeyboardController(Game *game) : InputController(game) {

}

void KeyboardController::readInput(const sf::Event &event) {
    if (event.type == sf::Event::KeyReleased) {
        std::string msg;
        if (event.key.code == UP) {
            msg = "UP";
        } else if (event.key.code == DOWN) {
            msg = "DOWN";
        } else if (event.key.code == LEFT) {
            msg = "LEFT";
        } else if (event.key.code == RIGHT) {
            msg = "RIGHT";
        } else if (event.key.code == ATTACK) {
            msg = "ATTACK";
        } else if (event.key.code == INTERACT) {
            msg = "INTERACT";
        }
        std::cout << msg << std::endl;
    }
}