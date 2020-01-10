#pragma once

#include <string>

struct ResourceSpec {
    ResourceSpec(std::string name, std::string path) : name(name), path(path) {}

    std::string name;
    std::string path;
};
