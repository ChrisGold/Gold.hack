//
// Created by y0079849 on 1/17/20.
//

#pragma once


#include <string>

class Item {
public:
    Item(const std::string &name, int icon_texture_id, int tile_texture_id, int attack, int range, int durability,
         int toughness);

private:
    std::string name;
public:
    [[nodiscard]] const std::string &getName() const;

private:
    int icon_texture_id;
    int tile_texture_id;
    int attack;
    int range;
    int durability;
    int toughness;
};


