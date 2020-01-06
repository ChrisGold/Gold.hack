#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Text.hpp>
#include <utility>
#include "Inventory.h"
#include "../resources/Fonts.h"
#include "../Constants.h"

void Inventory::draw(sf::RenderTarget &target, Fonts &fonts) {
    target.clear();
    //Draw name
    sf::Text nameText;
    nameText.setFont(fonts.getByName(FONT_DEFAULT));
    nameText.setString(name);
    nameText.setCharacterSize(30);
    nameText.setPosition(0, 0);
    nameText.setFillColor(sf::Color::White);
    target.draw(nameText);
}

Inventory::Inventory(std::string name) : name(std::move(name)) {}
