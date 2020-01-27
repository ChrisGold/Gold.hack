#include <utility>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include "Inventory.h"
#include "../resources/Resources.h"
#include "../Game.h"

void Inventory::draw(sf::RenderTarget &target, Resources &resources, Game *game) {
    target.clear();
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
        resources.render(target, itemRect, currentItem().getIconTexture());
        left += size;
    }

    top = top + 100;
    sf::RectangleShape healthBar{sf::Vector2f(game->currentLevel()->player->getHealth(), 20)};
    healthBar.setFillColor(sf::Color::Red);
    healthBar.setPosition(0, top);
    target.draw(healthBar);
}

Inventory::Inventory(std::string name) : name(std::move(name)) {
    selected_item = 0;
    items.emplace_back("Sword", 25, 1, 100, 10, "sword");
    items.emplace_back("Sword", 25, 1, 100, 10, "sword");
    items.emplace_back("Sword", 25, 1, 100, 10, "sword");
    items.emplace_back("Sword", 100, 1, 100, 10, "sword");
    items.emplace_back("Sword", 25, 1, 100, 10, "sword");
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
