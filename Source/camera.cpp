#include "camera.hpp"

camera::camera(object_ptr object):
		object{object}
{}


void camera::follow(sf::RenderWindow &window) {
	sf::View playerCam(sf::FloatRect(0, 0, 100 * 14, 100 * 9));
        
	sf::Vector2f player_midpoint = object->get_position();
	player_midpoint.x += object->get_size().x / 2;
	player_midpoint.y += object->get_size().y / 2;
        
	playerCam.setCenter(player_midpoint);
	window.setView(playerCam);
}