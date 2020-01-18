#pragma once

#include "IsometricMapSprite.h"

// Map node
class IsometricMapNode {
public:
    IsometricMapNode();

    ~IsometricMapNode();

    void drawFloors(sf::RenderTarget *win, sf::Color &color);

    void drawObjects(sf::RenderTarget *win, sf::Color &color);

    void drawWalls(sf::RenderTarget *win, sf::Color &color);

    void drawRoofs(sf::RenderTarget *win, sf::Color &color);

    void addFloor(IsometricMapSprite *s);

    void addWall(IsometricMapSprite *s);

    void addRoof(IsometricMapSprite *s);

    void insertSprite(IsometricMapSprite *s);

    void removeSprite(IsometricMapSprite *s);

    void clear();


protected:

    std::list<IsometricMapSprite *> m_floors, m_walls, m_roofs, m_objects;
};
