#pragma once

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Image.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "SFML/Graphics/Texture.hpp"
#include "../resources/Resources.h"
#include <list>
#include <vector>
#include <SFML/System.hpp>

/*
 * Adapted from: https://www.gamedev.net/blogs/entry/2250273-isometric-map-in-sfml/
 * by Christian Goldapp, original work of JTippetts
 */

/************************************************************
IsometricMap

Implement a basic isometric map using SFML sprites.

************************************************************/

// Class to wrap up a sprite to include a world position
class IsometricMapSprite : public sf::Sprite {
public:
    IsometricMapSprite();

    IsometricMapSprite(sf::Texture *texture, const sf::Vector2f &position = sf::Vector2f(0, 0),
                       const sf::Vector2f &scale = sf::Vector2f(1, 1), float rotation = 0.f,
                       const sf::Color &color = sf::Color(255, 255, 255, 255));

    ~IsometricMapSprite();

    void SetWorldPosition(float x, float y);

    void SetWorldPosition(const sf::Vector2f &position);

    sf::Vector2f GetWorldPosition() const;

    void SetWorldZ(float z);

    float GetWorldZ() { return m_z; }

    void setUseLighting(bool use) { m_uselighting = use; }

    bool getUseLighting() { return m_uselighting; }

protected:
    sf::Vector2f m_worldpos;
    sf::Texture *m_texture;
    float m_z;
    bool m_uselighting;
};


