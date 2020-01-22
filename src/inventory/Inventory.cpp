#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Text.hpp>
#include <utility>
#include "Inventory.h"
#include "../Constants.h"
#include "../resources/Resources.h"

void Inventory::draw(sf::RenderTarget &target, Resources &resources) {
    target.clear();
    //Draw name
    sf::Text nameText;
    nameText.setFont(*resources.getFont("LiberationSerif-Regular"));
    nameText.setString(name);
    nameText.setCharacterSize(30);
    nameText.setPosition(0, 0);
    nameText.setFillColor(sf::Color::White);
    target.draw(nameText);
}

Inventory::Inventory(std::string name) : name(std::move(name)) {
    selected_item = 0;
    items.emplace_back("Sword", 25, 1, 100, 10, "sword");
}

int Inventory::currentAttack() {
    return this->items[this->selected_item].attack;
}
