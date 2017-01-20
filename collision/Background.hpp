#ifndef _BACKGROUND_HPP
#define _BACKGROUND_HPP

#include "drawables.hpp"
#include <SFML\Graphics.hpp>
#include <iostream>

class Background:public drawables
{
public:
	Background();
	void draw(sf::RenderWindow &window) override;
	void setup(sf::RectangleShape & backGroundShape, sf::Vector2f & backgroundSize, sf::Texture & backgroundTexture);

private:
	sf::RectangleShape backGroundShape;
	sf::Vector2f backgroundSize;
	sf::Texture backgroundTexture;
};
#endif
