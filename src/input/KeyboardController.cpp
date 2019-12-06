//
// Created by christian on 27.11.19.
//

#include <iostream>
#include "KeyboardController.h"
#include "../action/Walk.h"
#include "../action/Interact.h"

KeyboardController::KeyboardController(Game *game) : InputController(game) {

}

Action *KeyboardController::readInput(const sf::Event &event) {
    Action *action = nullptr;
    if (event.type == sf::Event::KeyReleased) {
        if (event.key.code == UP) {
            action = new Walk(this->game->currentLevel(), Direction::NORTH);
        } else if (event.key.code == DOWN) {
            action = new Walk(this->game->currentLevel(), Direction::SOUTH);
        } else if (event.key.code == LEFT) {
            action = new Walk(this->game->currentLevel(), Direction::WEST);
        } else if (event.key.code == RIGHT) {
            action = new Walk(this->game->currentLevel(), Direction::EAST);
        } else if (event.key.code == ATTACK) {
        } else if (event.key.code == INTERACT) {
            action = new Interact(this->game->currentLevel(), this->game->currentLevel()->player->facing);
        }
    }
    return action;
}