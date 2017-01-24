#include "wall.hpp"

wall::wall(sf::Vector2f position, sf::Vector2f size, sf::Color object_color):
        drawable{position, size, "WALL"},
        object_color{object_color},
        rectangle{size}
{}

void wall::draw(sf::RenderWindow & window){
    rectangle.setPosition(position);
    rectangle.setFillColor(object_color);
    window.draw(rectangle);
}

sf::FloatRect wall::getGlobalBounds(){
    return rectangle.getGlobalBounds();
}

std::string wall::object_information(){
    return drawable::object_information() +
            " (" + std::to_string(size.x) + ',' + std::to_string(size.y) + ") " +
            string_from_color(object_color);
}