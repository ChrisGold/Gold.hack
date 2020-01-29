#include <utility>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include "Inventory.h"
#include "../resources/Resources.h"
#include "../Game.h"

void Inventory::draw(sf::RenderTarget &target, Resources &resources, Game *game) {
    target.clear(dark_grey);
    //Draw name
    sf::Text nameText;
    nameText.setFont(*resources.getFont("LiberationSerif-Regular"));
    nameText.setString(name);
    nameText.setCharacterSize(30);
    nameText.setPosition(0, 0);
    nameText.setFillColor(sf::Color::White);
    target.draw(nameText);

    auto top = nameText.getGlobalBounds().height + 25;
    auto left = 5.f;
    for (int i = 0; i < items.size(); i++) {
        float size = 50;
        float offset = 12.5;
        if (i == selected_item) {
            size = 75;
            offset = 0;
        }
        auto itemRect = sf::FloatRect(left, top + offset, size, size);
        resources.render(target, itemRect, items[i].getIconTexture());
        left += size;
    }

    top = top + 100;
    int health = game->currentLevel()->player->getHealth();
    int maxHealth = game->currentLevel()->player->getMaxHealth();
    sf::RectangleShape healthBar{sf::Vector2f((200.0 / maxHealth) * health, 20)};
    healthBar.setFillColor(sf::Color::Red);
    healthBar.setPosition(50, top);
    target.draw(healthBar);

    top = top + 100;

    auto scoreText = textbox(target, resources, "Score: " + std::to_string(score), sf::Vector2f(20.f, top), 30);
    target.draw(scoreText);

    while (messages.size() >= message_limit) {
        messages.erase(messages.begin());
    }

    top += 50;
    for (auto msg : messages) {
        auto line = textbox(target, resources, msg, sf::Vector2f(20, top), 20);
        top += line.getGlobalBounds().height + 20.f;
        target.draw(line);
    }
}

sf::Text
Inventory::textbox(sf::RenderTarget &target, Resources &resources, std::string msg, sf::Vector2f pos, int char_size) {
    sf::Text message;
    message.setFont(*resources.getFont(1));
    message.setString(msg);
    message.setCharacterSize(char_size);

    message.setPosition(pos);
    message.setFillColor(sf::Color::White);

    return message;
}

Inventory::Inventory(std::string name) : name(std::move(name)) {
    selected_item = 0;
    items.emplace_back("Alpha Strike", 25, 1, 100, 10, "item1");
    items.emplace_back("Beta Strike", 25, 1, 100, 10, "item2");
    items.emplace_back("Gamma Strike", 25, 1, 100, 10, "item3");
}

Item &Inventory::currentItem() {
    return this->items[this->selected_item];
}

int Inventory::currentAttack() {
    return currentItem().attack;
}

void Inventory::scrollRight() {
    selected_item++;
    selected_item = selected_item % int(items.size());
}

void Inventory::scrollLeft() {
    selected_item--;
    selected_item += items.size();
    selected_item = selected_item % int(items.size());
}

int Inventory::addScore(int points) {
    score += points;
    return score;
}

int Inventory::getScore() const {
    return score;
}
