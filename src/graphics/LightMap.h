#pragma once

#include "IsometricMapSprite.h"
#include "DynamicLight.h"

class LightMap {
public:
    LightMap(int w, int h, int nodesize);

    ~LightMap();

    void resize(int w, int h);

    void clearStatic();

    void clearDynamic();

    void updateRegion(int sx, int sy, int num_nodes, int num_rows);

    DynamicLight *requestLight();

    void releaseLight(DynamicLight *light);

    sf::Color getLightValue(int x, int y);

    void setAmbient(float r, float g, float b);

    void addStaticLightCell(int x, int y, float r, float g, float b);

    void addStaticLightRadius(float x, float y, float r, float g, float b, float radius);

    void debugPrintLights();

protected:
    std::vector<sf::Vector3f> m_static;
    std::vector<sf::Vector3f> m_final;
    std::__cxx11::list<DynamicLight> m_lights;
    sf::Vector3f m_ambient;
    int m_width, m_height, m_nodesize;
};
