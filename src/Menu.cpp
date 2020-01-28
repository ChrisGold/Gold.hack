#include <SFML/Graphics/Text.hpp>
#include "Menu.h"
#include "Constants.h"
#include "Game.h"

void Menu::click(int x, int y) {
    std::cout << "Click: x=" << x << ", y=" << y << std::endl;
    next = 0;
    if (alphaBox.contains(x, y)) {
        difficulty = 0.8f;
    } else if (betaBox.contains(x, y)) {
        difficulty = 1.0f;
    } else if (gammaBox.contains(x, y)) {
        difficulty = 1.5f;
    } else next = MENU;
    std::cout << "Difficulty:" << difficulty << std::endl;
}

void Menu::tick(TickContext &ctx) {
    if (next != MENU) {
        ctx.game->level_advance();
        reset();
    }
}

void Menu::draw(sf::RenderTarget &target, Resources &resources) {
    target.clear(gold);
    sf::Text title;
    title.setFont(*resources.getFont(1));
    title.setString("Gold.HACK");
    title.setCharacterSize(100);

    sf::FloatRect textRect = title.getLocalBounds();
    title.setOrigin(textRect.left + textRect.width / 2.0f,
                    textRect.top + textRect.height / 2.0f);
    title.setPosition(sf::Vector2f(target.getSize().x / 2.0f, target.getSize().y / 3.0f));
    title.setFillColor(sf::Color::White);

    target.draw(title);

    float standoff = 30.f;
    sf::Vector2f pos = sf::Vector2f(target.getSize().x / 2.0f,
                                    title.getGlobalBounds().height + title.getGlobalBounds().top + 2 * standoff);
    sf::Text alpha = textbox(target, resources, "Difficulty Level Alpha", pos, 40);
    pos = sf::Vector2f(pos.x, pos.y + alpha.getGlobalBounds().height + standoff);
    sf::Text beta = textbox(target, resources, "Difficulty Level Beta", pos, 40);
    pos = sf::Vector2f(pos.x, pos.y + alpha.getGlobalBounds().height + standoff);
    sf::Text gamma = textbox(target, resources, "Difficulty Level Gamma", pos, 40);

    target.draw(alpha);
    alphaBox = alpha.getGlobalBounds();
    target.draw(beta);
    betaBox = beta.getGlobalBounds();
    target.draw(gamma);
    gammaBox = gamma.getGlobalBounds();
}

sf::Text
Menu::textbox(sf::RenderTarget &target, Resources &resources, std::string msg, sf::Vector2f pos, int char_size) {
    sf::Text message;
    message.setFont(*resources.getFont(1));
    message.setString(msg);
    message.setCharacterSize(char_size);

    sf::FloatRect textRect = message.getLocalBounds();
    message.setOrigin(textRect.left + textRect.width / 2.0f,
                      textRect.top + textRect.height / 2.0f);
    message.setPosition(pos);
    message.setFillColor(sf::Color::White);

    return message;
}

void Menu::reset() {
    next = MENU;
}

float Menu::getDifficulty() const {
    return difficulty;
}
