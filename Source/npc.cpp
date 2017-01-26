#include "npc.hpp"

mob::mob(sf::Vector2f position, std::string filename) :
	drawable(position, sf::Vector2f{ 0.0,0.0 }, "mob"),
	mob_animation(position, filename)
{
	size = mob_animation.get_size();
}

void mob::draw(sf::RenderWindow & window) {
	if (alive) {
		mob_animation.draw(window);
	}
}

sf::FloatRect mob::getGlobalBounds() {
	if (alive) {
		return mob_animation.getGlobalBounds();
	}
	return sf::FloatRect{ 0,0,0,0 };
}


void mob::die() {
	alive = false;
}

void mob::revive() {
	alive = true;
}

bool mob::get_live() {
	return alive;
}
