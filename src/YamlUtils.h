#pragma once

#include <SFML/System.hpp>
#include <yaml-cpp/node/node.h>

sf::Vector2i widthHeightFromYAML(YAML::Node coords);

sf::Vector2i xyFromYAML(YAML::Node coords);
