#pragma once

#include <string>
#include <queue>
#include "../resources/Resources.h"
#include "Item.h"

class Game;

/**
 * A class representing the Inventory of a player, as well as their game states.
 */
class Inventory {
    /**
     * The items the player holds, in order
     */
    std::vector<Item> items;
    /**
     * The id of the currenly selected item. Must always be between 0 and items.size()
     */
    int selected_item;
    /**
     * How many messages may be displayed at once
     */
    int message_limit = 5;
    /**
     * The current running score
     */
    int score = 0;
    /**
     * The energy the player has left
     */
    int energy = 100;
public:
    int getScore() const;

    /**
     * Try to use a certain amount of energy. On success, the energy will be deducted
     * @param e The amount of energy to use
     * @return true if there was enough, false if there was not.
     */
    bool useEnergy(int e);

    /**
     * Increase energy by a fixed amount
     */
    void recharge();

    /**
     * Create a new Inventory
     * @param name The name of the player
     */
    Inventory(std::string name);

    /**
     * The name of the player to display
     */
    std::string name;

    /**
     * Draw this inventory onto a specific target
     * @param target The target to draw onto
     * @param resources The resources to use when drawing
     * @param game The game context to use
     */
    void draw(sf::RenderTarget &target, Resources &resources, Game *game);

    /**
     * The current attack of this player, taking the selected item into account
     * @return the attack in HP units
     */
    int currentAttack();

    /**
     * @return The item currently selected
     */
    Item &currentItem();

    /**
     * Scroll left/decrement #selected_item by one
     */
    void scrollLeft();

    /**
     * Scroll right/increment #selected_item by one
     */
    void scrollRight();

    /**
     * Draw a new message onto the message view
     * @param message
     */
    void enterMessage(std::string message);

    /**
     * Create a textbox
     * @param target The place to draw to
     * @param resources The resources to use
     * @param msg The message to write
     * @param pos The position (referring to a top-left origin) the textbox should be placed at
     * @param char_size The text size
     * @return A textbox that must still be drawn onto the target
     */
    sf::Text textbox(sf::RenderTarget &target, Resources &resources, std::string msg, sf::Vector2f pos, int char_size);

    /**
     * The messages displayed on screen, to which new messages should be appended
     */
    std::vector<std::string> messages;

    /**
     * Add new points for this player
     * @param points The points to add
     * @return The new number of points
     */
    int addScore(int points);
};
