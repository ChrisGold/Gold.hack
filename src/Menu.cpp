#include <SFML/Graphics/Text.hpp>
#include "Menu.h"
#include "Constants.h"

void Menu::click(int x, int y) {

}

void Menu::tick(TickContext &ctx) {

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

    sf::Text message;
    message.setFont(*resources.getFont(1));
    message.setString("<<click to start game>>");
    message.setCharacterSize(40);

    textRect = message.getLocalBounds();
    message.setOrigin(textRect.left + textRect.width / 2.0f,
                      textRect.top + textRect.height / 2.0f);
    message.setPosition(sf::Vector2f(target.getSize().x / 2.0f, target.getSize().y / 3.0f * 2.f));
    message.setFillColor(sf::Color::White);

    target.draw(message);
}
