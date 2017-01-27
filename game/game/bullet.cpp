#include "bullet.hpp"

bullet::bullet(sf::Vector2f position, std::string filename, std::vector<mob_ptr> & all_mobs, objects_vector & objects) :
	drawable(position, sf::Vector2f(0.0, 0.0), "Bullet"),
	bullet_animation(position, filename),
	all_mobs(all_mobs),
	objects(objects)
{
	size = bullet_animation.get_size();
}

void bullet::draw(sf::RenderWindow & window) {
	//std::cout << current_offset.x << std::endl;
	if (current_offset.x == 5) {
		if (!correctly_scaled) {

			bullet_animation.setTextureRect(sf::IntRect(0, 0, int(size.x), int(size.y)));
			correctly_scaled = true;
		}
	}
	else if (current_offset.x == -5) {
		//std::cout << "Otherside scale" << std::endl;
		if (correctly_scaled) {
			bullet_animation.setTextureRect(sf::IntRect(int(size.x), 0, -int(size.x), int(size.y)));
			correctly_scaled = false;
		}
	}
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
	//std::cout << "Print hit:" << hit << std::endl;
	if (fire_position != sf::Vector2f(0, 0)) {
		bullet_animation.set_position(fire_position);
		position = fire_position;
		std::cout << "Position: " << fire_position.x << " " << fire_position.y << std::endl;
		hit = false;
		std::cout << "Hit after position change: " << hit << std::endl;
		
	}
	if (offset != sf::Vector2f(0, 0)) {
		current_offset = offset;
	}
	//hit = 0;

	for (auto & mob : all_mobs) {
		//std::cout << "Hit before collision" << hit << std::endl;
		std::cout << "Position bullet " << position.x << " " << position.y << std::endl;
		collision(mob);
		//std::cout << "Hit while checking mobs: " << hit << std::endl;
		if (hit) {
			std::cout << "Print hit while checking mobs:" << hit << std::endl;
			mob->die();
			hit = false;
			shoot_timeout = 0;
		}
	}
	//hit = false;

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