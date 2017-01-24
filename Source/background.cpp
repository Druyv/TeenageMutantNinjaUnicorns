#include "Background.hpp"
#include <string>

Background::Background(std::string filename):
	drawable(sf::Vector2f(0,0), sf::Vector2f(0, 0),"Background"),
	filename(filename)
{
	background_texture.loadFromFile(filename);
	background_sprite.setTexture(background_texture);
}

sf::FloatRect Background::getGlobalBounds() {
	return background_sprite.getGlobalBounds();
}

void Background::draw( sf::RenderWindow &window ) {
	window.draw(background_sprite);
}
