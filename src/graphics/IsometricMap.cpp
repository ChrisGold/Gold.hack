//
// Created by christian on 18.01.20.
//

#include "IsometricMap.h"
#include "LightMap.h"
#include "IsometricUtilities.h"

/**********************************************************************
IsometricMap
***********************************************************************/

IsometricMap::IsometricMap(Resources &res, int w, int h, int nodesize) : m_width(w), m_height(w), m_nodesize(nodesize),
                                                                         m_centerx(0),
                                                                         m_centery(0), m_lightmap(w, h, nodesize),
                                                                         resources(res) {
    m_nodes.resize(w * h);
}

IsometricMap::~IsometricMap() {
}

void IsometricMap::resize(int w, int h) {
    clear();
    m_nodes.resize(w * h);
}

void IsometricMap::clear() {
    for (int c = 0; c < m_width * m_height; ++c) m_nodes[c].clear();
    m_mappieces.clear();
}

void IsometricMap::insertSprite(IsometricMapSprite *s) {
    // Figure out which cell it lies within
    sf::Vector2f worldpos = s->GetWorldPosition();
    int cx = (int) (worldpos.x) / m_nodesize;
    int cy = (int) (worldpos.y) / m_nodesize;
    if (cx < 0) cx = 0;
    if (cx >= m_width) cx = m_width - 1;
    if (cy < 0) cy = 0;
    if (cy >= m_height) cy = m_height - 1;

    m_nodes[cy * m_width + cx].insertSprite(s);
}

void IsometricMap::removeSprite(IsometricMapSprite *s) {
    // Figure out which cell it lies within
    sf::Vector2f worldpos = s->GetWorldPosition();
    int cx = (int) (worldpos.x) / m_nodesize;
    int cy = (int) (worldpos.y) / m_nodesize;
    if (cx < 0) cx = 0;
    if (cx >= m_width) cx = m_width - 1;
    if (cy < 0) cy = 0;
    if (cy >= m_height) cy = m_height - 1;
    m_nodes[cy * m_width + cx].removeSprite(s);
}

sf::Vector2f IsometricMap::projectMouseCoords(int mx, int my, sf::RenderWindow *win) {
    // Calculate view
    sf::View view = win->getView();
    // Calculate coords of mouse relative to view
    sf::Vector2f center = WorldToScreen(sf::Vector2f(m_centerx, m_centery));
    sf::Vector2f viewsize = view.getSize();
    sf::Vector2f mousecoords = ScreenToWorld(
            sf::Vector2f((center.x - viewsize.x / 2.0f) + (float) mx, (center.y - viewsize.y / 2.0f) + (float) my));
    return mousecoords;
}

void IsometricMap::draw(sf::RenderWindow *win) {
    // Do a brain dead whole-map scan for now
    // Set view
    sf::View view = win->getView();
    // Reverse project center
    sf::Vector2f center = WorldToScreen(sf::Vector2f(m_centerx, m_centery));
    view.setCenter(center);
    win->setView(view);

    // Reverse-project top-left corner
    sf::Vector2f viewsize = view.getSize();
    sf::Vector2f topleft = ScreenToWorld(sf::Vector2f(center.x - viewsize.x / 2.0f, center.y - viewsize.y / 2.0f));
    int sx = (int) (topleft.x / (float) m_nodesize);
    int sy = (int) (topleft.y / (float) m_nodesize);

    // Move start location up and left one node. (subtract 1 from sx
    sx -= 2;

    // Calculate how many nodes across to draw
    // A node's total width on-screen is calculated as 4*nodesize
    int num_nodes_across = (int) viewsize.x / (m_nodesize * 4) + 4;

    // Calculate how many rows to draw
    // A node's total height on screen is calculated as 2*nodesize. Also, need to fudge it
    // a little bit by adding a value that approximates the maximum cell height to the size of the
    // viewport.
    int num_rows = (((int) viewsize.y + 512) / (m_nodesize * 2)) * 2;

    // Update lighting
    m_lightmap.updateRegion(sx, sy, num_nodes_across, num_rows);

    // drawing proceeds as thus:
    // We begin at some starting node and proceed across the row. At each step, we increment x and decrement y
    // to move to the next node.
    // When a row is done, we move to the next row. This is done by:
    // If the current row is "even", then we move to the next row by incrementing x. If the current row is odd, we
    // move to the next row by incrementing y instead.
    // On even rows, we draw num_nodes+1 nodes, else we draw num_nodes nodes.
    int rowincx = 1, rowincy = 0;
    int drawnodes = num_nodes_across + 1;

    int nodex = sx, nodey = sy;
    for (int row = 0; row < num_rows; ++row) {
        if (row & 1) {
            // Odd row
            rowincx = 0;
            rowincy = 1;
            drawnodes = num_nodes_across;
        } else {
            rowincx = 1;
            rowincy = 0;
            drawnodes = num_nodes_across + 1;
        }


        for (int node = 0; node < drawnodes; ++node) {
            // Calculate cell coords
            int cellx = nodex + node;
            int celly = nodey - node;
            if (cellx >= 0 && cellx < m_width && celly >= 0 && celly < m_height) {
                sf::Color color = m_lightmap.getLightValue(cellx, celly);
                m_nodes[celly * m_width + cellx].drawFloors(win, color);
            }
        }

        nodex = nodex + rowincx;
        nodey = nodey + rowincy;
    }
// draw objects
    nodex = sx, nodey = sy;
    for (int row = 0; row < num_rows; ++row) {
        if (row & 1) {
            // Odd row
            rowincx = 0;
            rowincy = 1;
            drawnodes = num_nodes_across;
        } else {
            rowincx = 1;
            rowincy = 0;
            drawnodes = num_nodes_across + 1;
        }


        for (int node = 0; node < drawnodes; ++node) {
            // Calculate cell coords
            int cellx = nodex + node;
            int celly = nodey - node;
            if (cellx >= 0 && cellx < m_width && celly >= 0 && celly < m_height) {
                sf::Color color = m_lightmap.getLightValue(cellx, celly);
                m_nodes[celly * m_width + cellx].drawObjects(win, color);
                m_nodes[celly * m_width + cellx].drawRoofs(win, color);
                m_nodes[celly * m_width + cellx].drawWalls(win, color);
            }
        }

        nodex = nodex + rowincx;
        nodey = nodey + rowincy;
    }
}

void IsometricMap::addLeftWall(int x, int y, int image_id) {
    m_mappieces.push_front(IsometricMapSprite());
    IsometricMapSprite *s = &(m_mappieces.front());
    sf::Texture *tex = resources.getTexture(image_id);
    s->setTexture(*tex);

    // Set the origin of the sprite
    // For left wall it is (w,h)
    unsigned int imgwidth = tex->getSize().x;
    unsigned int imgheight = tex->getSize().y;
    s->setOrigin((float) imgwidth, (float) imgheight);

    // Set position of the sprite
    // For left wall, set to (originx+nodesize, originy+nodesize)
    float ox = (float) m_nodesize * (float) x;
    float oy = (float) m_nodesize * (float) y;
    s->SetWorldPosition(sf::Vector2f(ox + (float) m_nodesize - 1.0f, oy + (float) m_nodesize - 1.0f));

    // Add to cell
    m_nodes[y * m_width + x].addWall(s);
}

void IsometricMap::addRightWall(int x, int y, int image_id) {
    m_mappieces.push_front(IsometricMapSprite());
    IsometricMapSprite *s = &(m_mappieces.front());
    sf::Texture *tex = resources.getTexture(image_id);
    s->setTexture(*tex);

    // Set the origin of the sprite
    // For right wall it is (0,h)
    unsigned int imgheight = tex->getSize().y;
    s->setOrigin((float) 0, (float) imgheight);

    // Set position of the sprite
    // For right wall, set to (originx+nodesize, originy+nodesize)
    float ox = (float) m_nodesize * (float) x;
    float oy = (float) m_nodesize * (float) y;
    s->SetWorldPosition(sf::Vector2f(ox + (float) m_nodesize - 1.0f, oy + (float) m_nodesize - 1.0f));

    // Add to cell
    m_nodes[y * m_width + x].addWall(s);
}

void IsometricMap::addFloor(int x, int y, int image_id) {
    m_mappieces.push_front(IsometricMapSprite());
    IsometricMapSprite *s = &(m_mappieces.front());
    sf::Texture *tex = resources.getTexture(image_id);
    s->setTexture(*tex);

    // Set the origin of the sprite
    // For floor it is (w/2,0)
    unsigned int imgwidth = tex->getSize().x;
    s->setOrigin((float) imgwidth / 2.0f, 0.0f);

    // Set position of the sprite
    // For floor, set to (originx, originy)
    float ox = (float) m_nodesize * (float) x;
    float oy = (float) m_nodesize * (float) y;
    s->SetWorldPosition(sf::Vector2f(ox, oy));

    // Add to cell
    m_nodes[y * m_width + x].addFloor(s);
}

void IsometricMap::addRoof(int x, int y, int image_id, float height) {
    m_mappieces.push_front(IsometricMapSprite());
    IsometricMapSprite *s = &(m_mappieces.front());
    sf::Texture *tex = resources.getTexture(image_id);
    s->setTexture(*tex);

    // Set the origin of the sprite
    // For roof it is (w/2,0)
    unsigned int imgwidth = tex->getSize().x;
    s->setOrigin((float) imgwidth / 2.0f, 0.0f);

    // Set position of the sprite
    // For roof, set to (originx, originy)
    float ox = (float) m_nodesize * (float) x;
    float oy = (float) m_nodesize * (float) y;
    s->SetWorldPosition(sf::Vector2f(ox, oy));
    s->SetWorldZ(height);

    // Add to cell
    m_nodes[y * m_width + x].addRoof(s);
}