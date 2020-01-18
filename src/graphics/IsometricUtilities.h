#pragma once

// Function to convert a world position to a screen (view) position
sf::Vector2f WorldToScreen(sf::Vector2f v);

// Function to convert a screen (view) position to a world position
sf::Vector2f ScreenToWorld(sf::Vector2f v);

// Function to find the right place in a list to insert a sprite
// Lists are sorted ascending, with the sort value equal to the sprite's center X and Y summed together.
std::list<IsometricMapSprite *>::iterator
findSpotInSpriteList(IsometricMapSprite *s, std::list<IsometricMapSprite *> &spritelist);