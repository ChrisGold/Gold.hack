//
// Created by christian on 27.11.19.
//

#include "KeyboardController.h"
#include "../Game.h"
#include "Input.h"

KeyboardController::KeyboardController(Game *game) : InputController(game) {

}

std::optional<Input> KeyboardController::readInput(const sf::Event &event) {
    if (event.type == sf::Event::KeyReleased) {
        if (event.key.code == KEY_UP) {
            return Input::UP;
        } else if (event.key.code == KEY_DOWN) {
            return Input::DOWN;
        } else if (event.key.code == KEY_LEFT) {
            return Input::LEFT;
        } else if (event.key.code == KEY_RIGHT) {
            return Input::RIGHT;
        } else if (event.key.code == KEY_ACTION_1) {
            return Input::ACTION_1;
        } else if (event.key.code == KEY_ACTION_2) {
            return Input::ACTION_2;
        } else if (event.key.code == KEY_SCROLL_LEFT) {
            return Input::SCROLL_LEFT;
        } else if (event.key.code == KEY_SCROLL_RIGHT) {
            return Input::SCROLL_RIGHT;
        }
    }
    return {};
}