#include "unicorn.hpp"
#include <iostream>


unicorn::unicorn(sf::Vector2f position, std::string filename):
        drawable{position, sf::Vector2f{1.0,1.0}, std::string{"Unicorn"}},
	unicorn_animation{image_from_file{position, filename}}
{}

void unicorn::draw(sf::RenderWindow & window) {
	if (going_left) {
		if (!correctly_scaled) {
			unicorn_animation.scale(sf::Vector2f(-1.0f, 1.0f));
			unicorn_animation.set_position( sf::Vector2f{unicorn_animation.get_position().x + unicorn_animation.get_size().x, unicorn_animation.get_position().y} );
			correctly_scaled = true;
		}
	}
	else if (!going_left) {
		if (correctly_scaled) {
			unicorn_animation.scale(sf::Vector2f(-1.0f, 1.0f));
			unicorn_animation.set_position(sf::Vector2f{ unicorn_animation.get_position().x - unicorn_animation.get_size().x, unicorn_animation.get_position().y });
			correctly_scaled = false;
		}
	}
	unicorn_animation.draw(window);
}

void unicorn::move(sf::Vector2f delta) {
	unicorn_animation.move(delta);
}

void unicorn::run_actions() {
	for (auto & actions : actions_array) {
		actions();
	}
}

sf::FloatRect unicorn::getGlobalBounds() {
	return unicorn_animation.getGlobalBounds();
}

void unicorn::shoot(sf::Vector2f fire_position) {
	if (shoot_timeout == 100) {
		// Hier bullet object aanmaken en .fire doen met unicorn positie
	}
	if (shoot_timeout) {
		// Hier draw doen
	}
}