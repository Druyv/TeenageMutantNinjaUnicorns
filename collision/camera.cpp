#include "camera.hpp"

camera::camera(blok & Unicorn):
		Unicorn(Unicorn)
{
	
}


void camera::follow(sf::RenderWindow &window) {
	sf::View playerCam(sf::FloatRect(0, 0, (Unicorn.GetSize().x) * 4, (Unicorn.GetSize().y) * 4));
	sf::Vector2f MidPointOfPlayer = Unicorn.GetMiddle();
	/*	
	Player object requires this funtion. 
		sf::Vector2f blok::GetMiddle() {
			sf::Vector2f mid(position.x + (size.x / 2), position.y + (size.y / 2));
			return mid;
		}	
	*/
	playerCam.setCenter(MidPointOfPlayer);
	window.setView(playerCam);
}