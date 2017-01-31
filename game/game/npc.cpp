#include "npc.hpp"

mob::mob(sf::Vector2f position, std::string filename) :
	drawable(position, sf::Vector2f{ 0.0,0.0 }, "MOB"),
	mob_animation(position, filename)
{
	size = mob_animation.get_size();
}

void mob::draw(sf::RenderWindow & window) {
	//std::cout << "Mob: " << (bool)alive << std::endl;
	if (alive) {
		//std::cout << "Position mob when alive: " << position.x << " " << position.y << std::endl;
		mob_animation.draw(window);
	}
}

sf::FloatRect mob::getGlobalBounds() {
	//if (alive) {
		return mob_animation.getGlobalBounds();
	//}
	//return sf::FloatRect{ 0,0,0,0 };
}


void mob::die() {
	std::cout << "Mob died" << std::endl;
        std::cout << "GlobalBounds npc after (posx posy sizex size y): " << getGlobalBounds().left << ','
                                                                   << getGlobalBounds().top << ','
                                                                   << getGlobalBounds().width << ','
                                                                   << getGlobalBounds().height << '\n';
        set_position(sf::Vector2f{0,0});
        std::cout << "GlobalBounds npc after (posx posy sizex size y): " << getGlobalBounds().left << ','
                                                                   << getGlobalBounds().top << ','
                                                                   << getGlobalBounds().width << ','
                                                                   << getGlobalBounds().height << '\n';
	alive = false;
}

void mob::revive() {
        set_position(position);
        alive = true;
}

bool mob::get_live() {
	return alive;
}

void mob::set_position(sf::Vector2f new_position){
    mob_animation.set_position(new_position);
}