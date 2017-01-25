#include "background.hpp"
#include <string>

Background::Background(std::string filename):
background_image{
	 image_from_file(sf::Vector2f(0,0),filename)
}
{}

void Background::draw( sf::RenderWindow &window ) {
	background_image.draw(window);
}
