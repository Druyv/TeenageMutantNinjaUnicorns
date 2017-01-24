#include "camera.hpp"

camera::camera(object_ptr Unicorn):
		Unicorn(Unicorn)
{
	
}


void camera::follow(sf::RenderWindow &window) {
	sf::View playerCam(sf::FloatRect(0, 0, 100 * 14, 100 * 9));
	sf::Vector2f MidPointOfPlayer = Unicorn->get_position();
	MidPointOfPlayer.x += Unicorn->get_size().x / 2;
	MidPointOfPlayer.y += Unicorn->get_size().y / 2;
	/*	
	Player object requires this funtion. 
		sf::Vector2f unicorn::GetMiddle() {
			sf::Vector2f mid(position.x + (size.x / 2), position.y + (size.y / 2));
			return mid;
		}	
	*/
	playerCam.setCenter(MidPointOfPlayer);
	window.setView(playerCam);
}