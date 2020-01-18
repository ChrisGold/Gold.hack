//
// Created by christian on 18.01.20.
//

#include "IsometricMapNode.h"
#include "IsometricUtilities.h"

/*************************************************
IsometricMapNode
**************************************************/

IsometricMapNode::IsometricMapNode() = default;

IsometricMapNode::~IsometricMapNode() = default;

void IsometricMapNode::addFloor(IsometricMapSprite *s) {
    m_floors.push_back(s);
}

void IsometricMapNode::addWall(IsometricMapSprite *s) {
    m_walls.push_back(s);
}

void IsometricMapNode::addRoof(IsometricMapSprite *s) {
    m_roofs.push_back(s);
}

void IsometricMapNode::drawFloors(sf::RenderTarget *win, sf::Color &color) {
    for (auto iter = m_floors.begin(); iter != m_floors.end(); ++iter) {
        if ((*iter)->getUseLighting()) (*iter)->setColor(color);
        sf::Drawable *sprite = *iter;
        win->draw(*sprite);
    }
}

void IsometricMapNode::drawObjects(sf::RenderTarget *win, sf::Color &color) {
    for (auto iter = m_objects.begin(); iter != m_objects.end(); ++iter) {
        if ((*iter)->getUseLighting()) (*iter)->setColor(color);
        auto *s = static_cast<sf::Sprite *>(*iter);
        win->draw(*s);
    }
}

void IsometricMapNode::drawWalls(sf::RenderTarget *win, sf::Color &color) {
    for (auto iter = m_walls.begin(); iter != m_walls.end(); ++iter) {
        if ((*iter)->getUseLighting()) (*iter)->setColor(color);
        win->draw(*(static_cast<sf::Sprite *>(*iter)));
    }
}

void IsometricMapNode::drawRoofs(sf::RenderTarget *win, sf::Color &color) {
    for (auto iter = m_roofs.begin(); iter != m_roofs.end(); ++iter) {
        if ((*iter)->getUseLighting()) (*iter)->setColor(color);
        win->draw(*(static_cast<sf::Sprite *>(*iter)));
    }
}

void IsometricMapNode::insertSprite(IsometricMapSprite *s) {
    sf::Vector2f worldpos = s->GetWorldPosition();
    auto iter = findSpotInSpriteList(s, m_objects);
    m_objects.insert(iter, s);
    m_objects.unique();
}

void IsometricMapNode::removeSprite(IsometricMapSprite *s) {
    m_objects.remove(s);
}

void IsometricMapNode::clear() {
    m_floors.clear();
    m_walls.clear();
    m_roofs.clear();
    m_objects.clear();
}