#include <SFML/Graphics/Text.hpp>
#include "Menu.h"
#include "Constants.h"

void Menu::click(int x, int y) {

}

void Menu::tick(TickContext &ctx) {

}

void Menu::draw(sf::RenderTarget &target, TileSet &tileset, TextureSet &textureset, Fonts &fonts) {
    target.clear(light_gray);
    sf::Text title;
    title.setFont(fonts.getByName(FONT_DEFAULT));
    title.setString("Gold.HACK");
    title.setCharacterSize(30);
    title.setPosition(0, 0);
    title.setFillColor(goldenrod);
    target.draw(title);
}
