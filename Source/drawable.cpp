#include "drawable.hpp"

drawable::drawable(const sf::Vector2f & position, const sf::Vector2f & size, std::string name):
	position{position},
	size{size},
	name{name}
{}

void drawable::move(sf::Vector2f delta) {
	position += delta;
}

char drawable::collision(drawable& other) {
    return 'N';
}

void drawable::jump(sf::Vector2f new_location) {
	position = new_location;
}