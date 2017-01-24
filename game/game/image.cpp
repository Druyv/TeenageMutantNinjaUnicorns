#include "image.hpp"

image_from_file::image_from_file(sf::Vector2f position, std::string image_name) :
	drawable{ position, sf::Vector2f{ 0,0 }, "PICTURE" },
	image_name{ image_name }
{
	if (!texture.loadFromFile(image_name)) {
		throw image_load_error{ image_name };
	}

	image.setTexture(texture);
	size = (sf::Vector2f)texture.getSize();
}

void image_from_file::draw(sf::RenderWindow & window) {
	image.setPosition(position);
	window.draw(image);
}

sf::FloatRect image_from_file::getGlobalBounds() {
	return image.getGlobalBounds();
}

void image_from_file::set_position(sf::Vector2f new_position) {
	position = new_position;
}


void image_from_file::set_size(sf::Vector2f new_size) {
	size = new_size;
}

void image_from_file::setTextureRect(const sf::IntRect & rectangle) {
	image.setTextureRect(rectangle);
}