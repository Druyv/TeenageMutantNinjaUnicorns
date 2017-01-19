#include "unicorn.hpp"
#include <iostream>


unicorn::unicorn(sf::Vector2f position, std::string filename):
	unicorn_animation(image_from_file(position, filename)),
	drawable(position, /*get size functie toevoegen*/ sf::Vector2f(1.0,1.0), std::string("Unicorn"))
{
	//unicorn_animation_left.move(position);
}

//Even een vraag over stellen 
unicorn::~unicorn()
{
}

void unicorn::draw(sf::RenderWindow & window) {
	if (going_left) {
		if (!correctly_scaled) {
			unicorn_animation.scale(sf::Vector2f(-1.0f, 1.0f));
			unicorn_animation.SetPosition( sf::Vector2f{unicorn_animation.GetPosition().x + unicorn_animation.GetSize().x, unicorn_animation.GetPosition().y} );
			correctly_scaled = true;
		}
	}
	else if (going_right) {
		if (correctly_scaled) {
			unicorn_animation.scale(sf::Vector2f(-1.0f, 1.0f));
			unicorn_animation.SetPosition(sf::Vector2f{ unicorn_animation.GetPosition().x - unicorn_animation.GetSize().x, unicorn_animation.GetPosition().y });
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