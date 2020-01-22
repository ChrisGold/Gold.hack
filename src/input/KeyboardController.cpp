//
// Created by christian on 27.11.19.
//

#include "KeyboardController.h"
#include "../Game.h"

KeyboardController::KeyboardController(Game *game) : InputController(game) {

}

std::optional<Input> KeyboardController::readInput(const sf::Event &event) {
    std::optional<Input> i{};
    if (event.type == sf::Event::KeyReleased) {
        if (event.key.code == KEY_UP) {
            i = Input::UP;
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) {
                i = Input::TURN_UP;
            }
        } else if (event.key.code == KEY_DOWN) {
            i = Input::DOWN;
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) {
                i = Input::TURN_DOWN;
            }
        } else if (event.key.code == KEY_LEFT) {
            i = Input::LEFT;
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) {
                i = Input::TURN_LEFT;
            }
        } else if (event.key.code == KEY_RIGHT) {
            i = Input::RIGHT;
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) {
                i = Input::TURN_RIGHT;
            }
        } else if (event.key.code == KEY_ACTION_1) {
            i = Input::ACTION_1;
        } else if (event.key.code == KEY_ACTION_2) {
            i = Input::ACTION_2;
        } else if (event.key.code == KEY_SCROLL_LEFT) {
            i = Input::SCROLL_LEFT;
        } else if (event.key.code == KEY_SCROLL_RIGHT) {
            i = Input::SCROLL_RIGHT;
        }
        return i;
    }
}