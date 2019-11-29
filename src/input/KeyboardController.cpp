//
// Created by christian on 27.11.19.
//

#include <iostream>
#include "KeyboardController.h"
#include "../action/Walk.h"

KeyboardController::KeyboardController(Game *game) : InputController(game) {

}

ActionPtr KeyboardController::readInput(const sf::Event &event) {
    ActionPtr action = nullptr;
    if (event.type == sf::Event::KeyReleased) {
        std::string msg;
        if (event.key.code == UP) {
            action = new Walk(this->game, this->game->currentLevel(), Direction::NORTH);
            msg = "UP";
        } else if (event.key.code == DOWN) {
            action = new Walk(this->game, this->game->currentLevel(), Direction::SOUTH);
            msg = "DOWN";
        } else if (event.key.code == LEFT) {
            action = new Walk(this->game, this->game->currentLevel(), Direction::WEST);
            msg = "LEFT";
        } else if (event.key.code == RIGHT) {
            action = new Walk(this->game, this->game->currentLevel(), Direction::EAST);
            msg = "RIGHT";
        } else if (event.key.code == ATTACK) {
            msg = "ATTACK";
        } else if (event.key.code == INTERACT) {
            msg = "INTERACT";
        }
        std::cout << msg << std::endl;
    }
    return action;
}