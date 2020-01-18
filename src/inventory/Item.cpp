//
// Created by y0079849 on 1/17/20.
//

#include "Item.h"

Item::Item(const std::string &name, int attack, int range, int durability, int toughness) : name(name), attack(attack),
                                                                                            range(range),
                                                                                            durability(durability),
                                                                                            toughness(toughness) {}

const std::string &Item::getName() const {
    return name;
}
