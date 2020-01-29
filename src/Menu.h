#pragma once

#include <SFML/Graphics/RenderTarget.hpp>
#include "TickContext.h"
#include "resources/Resources.h"
#include "GameStage.h"

enum MenuState {
    PREGAME, WIN, LOSS, OVER
};

class Menu {
    GameStage next = MENU;
    MenuState state = PREGAME;
public:
    MenuState getState() const;

public:
    void setState(MenuState state);

private:
    float difficulty = 1.0f;
    sf::FloatRect alphaBox;
    sf::FloatRect betaBox;
    sf::FloatRect gammaBox;
public:
    float getDifficulty() const;

public:
    void draw(sf::RenderTarget &target, Resources &resources);

    void reset();

    void tick(TickContext &ctx);

    void click(int x, int y);

    sf::Text textbox(sf::RenderTarget &target, Resources &resources, std::string msg, sf::Vector2f pos, int char_size);

    void drawPregame(sf::RenderTarget &target, Resources &resources);

    sf::Text drawTitle(sf::RenderTarget &target, Resources &resources, std::string);
};
