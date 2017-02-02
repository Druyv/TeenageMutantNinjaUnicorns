#include "wall.hpp"

wall::wall(sf::Vector2f position, sf::Vector2f size, sf::Color object_color, std::string image_name):
    drawable{position, size, "WALL"},
    object_color{object_color},
    rectangle{size},
    image_name{image_name}
{
    if (image_name != ""){
        if (!texture.loadFromFile(image_name)) {
            throw image_load_error{image_name};
        }
        rectangle.setTexture(&texture);
    }
}
       
void wall::draw(sf::RenderWindow & window){
    rectangle.setPosition(position);
    rectangle.setSize(size);
    rectangle.setFillColor(object_color);
    window.draw(rectangle);
}

sf::FloatRect wall::getGlobalBounds(){
    return rectangle.getGlobalBounds();
}

std::string wall::object_information(){
    return drawable::object_information() +
            " (" + std::to_string(size.x) + ',' + std::to_string(size.y) + ") " +
            string_from_color(object_color) + ' ' +
            image_name;
}