#include "Background.hpp"
#include <string>

Background::Background(std::string str):
	str(str)
{
	setup(backGroundShape, backgroundSize,backgroundTexture);
}

void Background::setup(sf::RectangleShape & backGroundShape, sf::Vector2f & backgroundSize, sf::Texture & backgroundTexture) {
	if (str == "x" ) {
		if (!backgroundTexture.loadFromFile("C:\\V2CPSE2-msvc-01\\03-08 array of actions\\Debug\\background.png")) {
			std::cout << "Could not load background image";
		};
		backgroundTexture.setSmooth(true);
		backgroundTexture.setRepeated(true);

		backgroundSize.x = 1920;
		backgroundSize.y = 1080;

		backGroundShape.setTexture(&backgroundTexture);
		backGroundShape.setSize(backgroundSize);
	}
	else {
		std::string ConstructedPath = "C:\\V2CPSE2-msvc-01\\03-08 array of actions\\Debug\\" + str;
		if (!backgroundTexture.loadFromFile(ConstructedPath)) {
			std::cout << "Could not load background image";
		};
		backgroundTexture.setSmooth(true);
		backgroundTexture.setRepeated(true);

		backgroundSize.x = 1920;
		backgroundSize.y = 1080;

		backGroundShape.setTexture(&backgroundTexture);
		backGroundShape.setSize(backgroundSize);
	}
	
}

void Background::draw( sf::RenderWindow &window ) {
	window.draw(backGroundShape);
}
