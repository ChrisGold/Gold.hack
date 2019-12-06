//
// Created by christian on 27.11.19.
//

#include <iostream>
#include "KeyboardController.h"
#include "../action/Walk.h"
#include "../action/Interact.h"

KeyboardController::KeyboardController(GamePtr game) : InputController(game) {

}

ActionPtr KeyboardController::readInput(const sf::Event &event) {
    ActionPtr action = nullptr;
    if (event.type == sf::Event::KeyReleased) {
        if (event.key.code == UP) {
            action = new Walk(this->game, this->game->currentLevel(), Direction::NORTH);
        } else if (event.key.code == DOWN) {
            action = new Walk(this->game, this->game->currentLevel(), Direction::SOUTH);
        } else if (event.key.code == LEFT) {
            action = new Walk(this->game, this->game->currentLevel(), Direction::WEST);
        } else if (event.key.code == RIGHT) {
            action = new Walk(this->game, this->game->currentLevel(), Direction::EAST);
        } else if (event.key.code == ATTACK) {
        } else if (event.key.code == INTERACT) {
            action = new Interact(this->game, this->game->currentLevel(), Direction::SOUTH);
        }
    }
    return action;
}