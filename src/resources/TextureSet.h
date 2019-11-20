#pragma once

#include <vector>
#include <memory>
#include <SFML/Graphics/Texture.hpp>

class TextureSet {
    std::vector<std::shared_ptr<sf::Texture>> textures;

    void load(std::string &file);

public:
    std::shared_ptr<const sf::Texture> getById(int id);

    void load(std::vector<std::string> &files);

    void render(sf::RenderTarget &target, const sf::FloatRect &rect, int obj_id);

    static TextureSet init();
};