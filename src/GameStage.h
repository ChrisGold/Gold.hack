#pragma once

#include <variant>

typedef std::variant<int, std::monostate> GameStage;
const GameStage MENU = std::monostate();