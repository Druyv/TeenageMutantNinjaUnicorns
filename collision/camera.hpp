#ifndef _CAMERA_HPP
#define _CAMERA_HPP

#include "blok.hpp"
#include <SFML\Graphics.hpp>
#include <iostream>

class camera{
public:
	camera(blok & Unicorn);
	void follow(sf::RenderWindow &window);
	void setup();

private:
	blok & Unicorn;
	sf::View playerCam;
};
#endif
