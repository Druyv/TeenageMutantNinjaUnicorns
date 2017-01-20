#include "Background.hpp"


Background::Background()
{
	setup(backGroundShape, backgroundSize,backgroundTexture);
}

void Background::setup(sf::RectangleShape & backGroundShape, sf::Vector2f & backgroundSize, sf::Texture & backgroundTexture) {

	backgroundTexture.loadFromFile("C:\\V2CPSE2-msvc-01\\03-08 array of actions\\Debug\\background.png");
	backgroundTexture.setSmooth(false);
	backgroundTexture.setRepeated(true);

	float bgY = 0;
	backgroundSize.x = 800;
	backgroundSize.y = 600;

	
	backGroundShape.setTexture(&backgroundTexture);
	backGroundShape.setSize(backgroundSize);
}


void Background::draw(sf::RenderWindow &window)
{
	window.draw(backGroundShape);
}
