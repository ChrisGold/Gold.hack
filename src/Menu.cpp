#include <SFML/Graphics/Text.hpp>
#include "Menu.h"
#include "Constants.h"

void Menu::click(int x, int y) {

}

void Menu::tick(TickContext &ctx) {

}

void Menu::draw(sf::RenderTarget &target, Resources &resources) {
    target.clear(light_gray);
    sf::Text title;
    title.setFont(resources.getFont(0));
    title.setString("Gold.HACK");
    title.setCharacterSize(30);
    title.setPosition(0, 0);
    title.setFillColor(goldenrod);
    target.draw(title);
}
