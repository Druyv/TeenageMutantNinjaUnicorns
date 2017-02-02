#include "npc.hpp"

mob::mob(sf::Vector2f position, std::string filename) :
    drawable{position, sf::Vector2f{ 0.0,0.0 }, "MOB"},
    mob_animation{position, filename}
{
    size = mob_animation.get_size();
}

void mob::draw(sf::RenderWindow & window) {
    if (is_alive) {
        mob_animation.draw(window);
    }
}

sf::FloatRect mob::getGlobalBounds() {
    return mob_animation.getGlobalBounds();
}


void mob::die() {
    set_position(sf::Vector2f{0,0});
    is_alive = false;
}

void mob::revive() {
    set_position(position);
    is_alive = true;
}

bool mob::get_live() {
    return is_alive;
}

void mob::set_position(sf::Vector2f new_position){
    mob_animation.set_position(new_position);
}