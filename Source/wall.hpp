#ifndef _WALL_HPP
#define _WALL_HPP
#include "drawable.hpp"

class wall : public drawable {
    public:
        wall(sf::Vector2f position, sf::Vector2f size, sf::Color object_color);
        void draw(sf::RenderWindow & window) override;
        sf::FloatRect getGlobalBounds() override;
        std::string object_information() override;
    private:
        sf::Color object_color;
        sf::RectangleShape rectangle;
};

#endif //_WALL_HPP
