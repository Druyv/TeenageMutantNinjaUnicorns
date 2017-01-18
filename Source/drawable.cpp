#include "drawable.hpp"

drawable::drawable(const sf::Vector2f & position, const sf::Vector2f & size, std::string name):
	position(position),
	size(size),
	name(name)
{}

void drawable::move(sf::Vector2f delta) {
	position += delta;
}

bool drawable::intersects(drawable & other) {
	return getGlobalBounds().intersects(other.getGlobalBounds());
}

void drawable::jump(sf::Vector2f new_location) {
	position = new_location;
}

/*
void drawable::output_options(std::ofstream & file) {
	if (name != "NONE") {
		file << '(' << location.x << ',' << location.y << ") " << name << ' ';
	}
}*/