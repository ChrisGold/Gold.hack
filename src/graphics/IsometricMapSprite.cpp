#include "IsometricMapSprite.h"
#include "IsometricMap.h"
#include "LightMap.h"
#include "IsometricMapNode.h"
#include "IsometricUtilities.h"
#include "../Constants.h"
#include <algorithm>
#include <cmath>
#include <iostream>


/********************************************
IsometricMapSprite
*********************************************/
IsometricMapSprite::IsometricMapSprite()
        : sf::Sprite(), m_worldpos(0, 0), m_texture(EMPTY_TEXTURE) { m_uselighting = true; }

IsometricMapSprite::IsometricMapSprite(sf::Texture *texture, const sf::Vector2f &position,
                                       const sf::Vector2f &scale, float rotation, const sf::Color &color) :
        sf::Sprite(), m_texture(texture) {
    setScale(scale.x, scale.y);
    setRotation(rotation);
    setColor(color);
    m_worldpos = position;
    m_z = 0;
    sf::Vector2f screenpos = WorldToScreen(m_worldpos);
    screenpos.y -= m_z;
    setPosition(screenpos);
    m_uselighting = true;
}

IsometricMapSprite::~IsometricMapSprite() {}

void IsometricMapSprite::SetWorldPosition(float x, float y) {
    m_worldpos = sf::Vector2f(x, y);
    sf::Vector2f screenpos = WorldToScreen(m_worldpos);
    screenpos.y -= m_z;
    setPosition(screenpos);
}

void IsometricMapSprite::SetWorldPosition(const sf::Vector2f &position) {
    m_worldpos = position;
    sf::Vector2f screenpos = WorldToScreen(m_worldpos);
    screenpos.y -= m_z;
    setPosition(screenpos);
}

void IsometricMapSprite::SetWorldZ(float z) {
    m_z = z;
    sf::Vector2f screenpos = WorldToScreen(m_worldpos);
    screenpos.y -= m_z;
    setPosition(screenpos);
}

sf::Vector2f IsometricMapSprite::GetWorldPosition() const {
    return m_worldpos;
}


