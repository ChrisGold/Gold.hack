//
// Created by christian on 27.11.19.
//

#include <iostream>
#include "KeyboardController.h"
#include "../action/Walk.h"
#include "../action/Interact.h"
#include "../Game.h"
#include "../action/Attack.h"

KeyboardController::KeyboardController(Game *game) : InputController(game) {

}

Action *KeyboardController::readInput(const sf::Event &event) {
    Action *action = nullptr;
    if (event.type == sf::Event::KeyReleased) {
        if (event.key.code == UP) {
            action = new Walk(Direction::NORTH);
        } else if (event.key.code == DOWN) {
            action = new Walk(Direction::SOUTH);
        } else if (event.key.code == LEFT) {
            action = new Walk(Direction::WEST);
        } else if (event.key.code == RIGHT) {
            action = new Walk(Direction::EAST);
        } else if (event.key.code == ATTACK) {
            action = new Attack(this->game->currentLevel()->player->facing);
        } else if (event.key.code == INTERACT) {
            action = new Interact(this->game->currentLevel()->player->facing);
        }
    }
    return action;
}