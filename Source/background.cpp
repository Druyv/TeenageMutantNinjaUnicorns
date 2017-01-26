#include "background.hpp"

background::background(std::string filename, sf::Vector2f level_size ):
drawable{ sf::Vector2f{0, 0}, level_size, "BACKGROUND" },
background_image{ sf::Vector2f(0,0), filename }
{
    background_image.set_smooth(true);
    background_image.set_repeated(true);
    background_image.set_scale(3,3);
    background_image.setTextureRect( {0, 0, (int)size.x, (int)size.y} );
}

void background::draw( sf::RenderWindow &window ) {
	background_image.draw(window);
}

sf::FloatRect background::getGlobalBounds(){
    return background_image.getGlobalBounds();
}