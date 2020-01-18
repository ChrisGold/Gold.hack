//
// Created by christian on 18.01.20.
//

#include <iostream>
#include <cmath>
#include "LightMap.h"

// LightMap
LightMap::LightMap(int w, int h, int nodesize) : m_ambient(1, 1, 1), m_width(w), m_height(h), m_nodesize(nodesize) {
    m_static.resize(w * h);
    m_final.resize(w * h);
    clearStatic();
}

LightMap::~LightMap() {
}

void LightMap::resize(int w, int h) {
    m_width = w;
    m_height = h;
    m_static.resize(w * h);
    m_final.resize(w * h);
    clearStatic();
    clearDynamic();
}

void LightMap::clearStatic() {
    for (int c = 0; c < m_width * m_height; ++c) {
        m_static[c] = sf::Vector3f(0, 0, 0);
        m_final[c] = sf::Vector3f(0, 0, 0);
    }
}

void LightMap::clearDynamic() {
    m_lights.clear();
}

void LightMap::debugPrintLights() {
    for (std::__cxx11::list<DynamicLight>::iterator iter = m_lights.begin(); iter != m_lights.end(); ++iter) {
        DynamicLight &l = (*iter);
        std::cout << "Light: (" << l.m_position.x << "," << l.m_position.y << ") Color: (" <<
                  l.m_color.x << "," << l.m_color.y << "," << l.m_color.z << ") Radius: " << l.m_radius << std::endl;
    }
}

void LightMap::updateRegion(int sx, int sy, int num_nodes, int num_rows) {
    int rowincx = 1, rowincy = 0;
    int drawnodes = num_nodes + 1;

    int nodex = sx, nodey = sy;
    for (int row = 0; row < num_rows; ++row) {
        if (row & 1) {
            // Odd row
            rowincx = 0;
            rowincy = 1;
            drawnodes = num_nodes;
        } else {
            rowincx = 1;
            rowincy = 0;
            drawnodes = num_nodes + 1;
        }


        for (int node = 0; node < drawnodes; ++node) {
            // Calculate cell coords
            int cellx = nodex + node;
            int celly = nodey - node;
            if (cellx >= 0 && cellx < m_width && celly >= 0 && celly < m_height) {
                // m_final[celly*m_width+cellx]=sf::Vector3f(0,0,0);
                // Calculate coord of center of point
                float cx = (float) cellx * (float) m_nodesize + (float) m_nodesize / 2.0f;
                float cy = (float) celly * (float) m_nodesize + (float) m_nodesize / 2.0f;

                // Set cell to ambient + static
                sf::Vector3f staticlight = m_static[celly * m_width + cellx];
                sf::Vector3f light(0, 0, 0);

                // Iterate dynamic lights
                for (std::__cxx11::list<DynamicLight>::iterator iter = m_lights.begin();
                     iter != m_lights.end(); ++iter) {
                    float dx = cx - (*iter).m_position.x, dy = cy - (*iter).m_position.y;
                    if (fabs(dx) <= (*iter).m_radius && fabs(dy) <= (*iter).m_radius) {
                        // Light is in range of point
                        float dist = sqrt(dx * dx + dy * dy);
                        float intensity = ((*iter).m_radius - dist) / (*iter).m_radius;
                        intensity = std::max(0.f, std::min(1.0f, intensity));  // Clamp it
                        light.x += (*iter).m_color.x * intensity;
                        light.y += (*iter).m_color.y * intensity;
                        light.z += (*iter).m_color.z * intensity;
                    }
                }
                m_final[celly * m_width + cellx] = sf::Vector3f(m_ambient.x + staticlight.x + light.x,
                                                                m_ambient.y + staticlight.y + light.y,
                                                                m_ambient.z + staticlight.z + light.z);


            }
        }

        nodex = nodex + rowincx;
        nodey = nodey + rowincy;
    }
}

DynamicLight *LightMap::requestLight() {
    m_lights.push_front(DynamicLight());
    return &m_lights.front();
}

void LightMap::releaseLight(DynamicLight *light) {
    m_lights.remove(*light);
}

sf::Color LightMap::getLightValue(int x, int y) {
    if (x < 0 || x >= m_width || y < 0 || y >= m_height) return sf::Color(0, 0, 0, 255);
    sf::Vector3f color = m_final[y * m_width + x];
    color.x = std::max(0.f, std::min(1.f, color.x));
    color.y = std::max(0.f, std::min(1.f, color.y));
    color.z = std::max(0.f, std::min(1.f, color.z));
    return sf::Color((unsigned char) (color.x * 255.0f), (unsigned char) (color.y * 255.0f),
                     (unsigned char) (color.z * 255.0f));
}

void LightMap::setAmbient(float r, float g, float b) {
    m_ambient = sf::Vector3f(r, g, b);
}

void LightMap::addStaticLightCell(int x, int y, float r, float g, float b) {
    if (x < 0 || x >= m_width || y < 0 || y >= m_height) return;
    sf::Vector3f &s = m_static[y * m_width + x];
    s.x += r;
    s.y += g;
    s.z += b;
}

void LightMap::addStaticLightRadius(float x, float y, float r, float g, float b, float radius) {
    // Get region of cells
    int sx = (int) ((x - radius) / (float) m_nodesize) - 1;
    int sy = (int) ((y - radius) / (float) m_nodesize) - 1;
    int dx = (int) ((x + radius) / (float) m_nodesize) + 1;
    int dy = (int) ((y + radius) / (float) m_nodesize) + 1;

    for (int cx = sx; cx <= dx; ++cx) {
        for (int cy = sy; cy <= dy; ++cy) {
            if (cx >= 0 && cx < m_width && cy >= 0 && cy < m_height) {
                sf::Vector3f st = m_static[cy * m_width + cx];
                float cellx = (float) cx * (float) m_nodesize + (float) m_nodesize / 2.0f;
                float celly = (float) cy * (float) m_nodesize + (float) m_nodesize / 2.0f;
                float dx = cellx - x, dy = celly - y;
                float dist = sqrt(dx * dx + dy * dy);
                float intensity = (radius - dist) / radius;
                intensity = std::max(0.f, std::min(1.0f, intensity));
                st.x += r * intensity;
                st.y += g * intensity;
                st.z += b * intensity;
                m_static[cy * m_width + cx] = st;
            }
        }
    }
}