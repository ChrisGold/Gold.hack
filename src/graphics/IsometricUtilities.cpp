#include <iostream>
#include <cmath>
#include <algorithm>
#include "IsometricMapNode.h"
#include "LightMap.h"
#include "IsometricMap.h"
#include "IsometricMapSprite.h"
#include "IsometricUtilities.h"

sf::Vector2f WorldToScreen(sf::Vector2f v) {
    return sf::Vector2f(2.0f * v.x - 2.0f * v.y, v.x + v.y);
}

sf::Vector2f ScreenToWorld(sf::Vector2f v) {
    return sf::Vector2f((v.x + 2.0f * v.y) / 4.0f, (2.0f * v.y - v.x) / 4.0f);
}

std::list<IsometricMapSprite *>::iterator
findSpotInSpriteList(IsometricMapSprite *s, std::list<IsometricMapSprite *> &spritelist) {
    auto iter = spritelist.begin();
    sf::Vector2f worldpos = s->GetWorldPosition();
    float z = s->GetWorldZ();
    float sortval = worldpos.x + worldpos.y + z;

    while (iter != spritelist.end()) {
        sf::Vector2f npos = (*iter)->GetWorldPosition();
        float nz = (*iter)->GetWorldZ();
        if (npos.x + npos.y + nz > sortval) return iter;
        ++iter;
    }
    return iter;
}
