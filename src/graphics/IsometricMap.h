#pragma once

#include "IsometricMapSprite.h"
#include "LightMap.h"
#include "IsometricMapNode.h"

class IsometricMap {
public:
    IsometricMap(Resources &res, int w, int h, int nodesize);

    ~IsometricMap();

    void resize(int w, int h);

    void clear();

    void insertSprite(IsometricMapSprite *s);

    void removeSprite(IsometricMapSprite *s);

    void draw(sf::RenderTarget *win);

    sf::Vector2f projectMouseCoords(int mx, int my, sf::RenderWindow *win);

    void addLeftWall(int x, int y, int image_id); // Set a left wall piece
    void addRightWall(int x, int y, int image_id);

    void addFloor(int x, int y, int image_id);

    void addRoof(int x, int y, int image_id, float height);

    void setCenter(float x, float y) {
        m_centerx = x;
        m_centery = y;
    }

    LightMap *getLightMap() { return &m_lightmap; }


protected:
    std::vector<IsometricMapNode> m_nodes;
    int m_width, m_height;
    int m_nodesize;
    float m_centerx, m_centery;
    std::__cxx11::list<IsometricMapSprite> m_mappieces;
    LightMap m_lightmap;
    Resources &resources;
};

