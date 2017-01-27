#ifndef _button_HPP
#define _button_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include "drawable.hpp"
#include "image.hpp"


class Button {
private:
	float startHeightY;
	float startHeightX;
	int position;

	std::string WhatsOnTheButton;
	sf::Texture texture;
	sf::Sprite ButtonBackground;

	sf::Font font;
	sf::Text text;

	
public:
	Button(float startHeightY = 0.0, float startHeightX = 0.0,int position = 0, std::string WhatsOnTheButton = " ");
	void setup();
	sf::FloatRect getGlobalBounds();
	void draw(sf::RenderWindow & window);
};



#endif
