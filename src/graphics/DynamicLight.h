#pragma once

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Image.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <list>
#include <vector>
#include <SFML/System.hpp>
#include "SFML/Graphics/Texture.hpp"
#include "../resources/Resources.h"

struct DynamicLight {
    DynamicLight() : m_position(0, 0), m_color(0, 0, 0), m_radius(0) {}

    ~DynamicLight() {}

    void setColor(float r, float g, float b) { m_color = sf::Vector3f(r, g, b); }

    void setRadius(float rad) { m_radius = rad; }

    void setPosition(float x, float y) { m_position = sf::Vector2f(x, y); }

    bool operator==(const DynamicLight &rhs) const {
        if (this == &rhs) return true;
        return false;
    }

    sf::Vector2f m_position;
    sf::Vector3f m_color;
    float m_radius;
};

