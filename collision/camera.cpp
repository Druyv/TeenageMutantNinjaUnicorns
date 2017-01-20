#include "camera.hpp"

camera::camera(blok & Unicorn):
		Unicorn(Unicorn)
{
	setup();
}

void camera::setup() {
	sf::View playerCam(sf::FloatRect(0, 0, (Unicorn.GetSize().x) * 4, (Unicorn.GetSize().y) * 4));
}

void camera::follow(sf::RenderWindow &window) {
	sf::Vector2f a = Unicorn.GetMiddle();
	sf::Vector2f b(a.x, a.y);
	playerCam.setCenter(b);
	window.setView(playerCam);
}