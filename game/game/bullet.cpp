#include "bullet.hpp"

bullet::bullet(sf::Vector2f position, std::string filename, std::vector<mob_ptr> & all_mobs, objects_vector & objects) :
    drawable{position, sf::Vector2f{0.0, 0.0}, "Bullet"},
    bullet_animation{position, filename},
    all_mobs{all_mobs},
    objects{objects}
{
    size = bullet_animation.get_size();
}

void bullet::draw(sf::RenderWindow & window) {
    if (!hit) {
        bullet_animation.draw(window);
    }
}

sf::FloatRect bullet::getGlobalBounds() {
    return bullet_animation.getGlobalBounds();
}

void bullet::projectile() {
    bullet_animation.move(current_offset);
}

template<typename P>
void bullet::collision(P unique_object) {
    hit = bool(getGlobalBounds().intersects(unique_object->getGlobalBounds()));
}


void bullet::shoot(sf::RenderWindow & window, int & shoot_timeout, sf::Vector2f offset, sf::Vector2f fire_position) {
    if (fire_position != sf::Vector2f(0, 0)) {
        bullet_animation.set_position(fire_position);
        position = fire_position;
        hit = false;
    }
    if (offset != sf::Vector2f(0, 0)) {
        current_offset = offset;
        if (current_offset.x > 0) {
            bullet_animation.setTextureRect(sf::IntRect(0, 0, int(size.x), int(size.y)));
        }
        else if (current_offset.x < 0) {
            bullet_animation.setTextureRect(sf::IntRect(int(size.x), 0, -int(size.x), int(size.y)));
        }
    }
    for (auto & mob : all_mobs) {
	collision(mob);
        if (hit) {
            mob->die();
            hit = false;
            shoot_timeout = 0;
        }
    }

    for (const auto & object : objects) {
        collision(object);
        if (hit) {
            hit = false;
            shoot_timeout = 0;
        }
    }
    projectile();
    draw(window);
}

void bullet::set_position(sf::Vector2f new_position){
    bullet_animation.set_position(new_position);
    position = new_position;
}