#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
class super {
public:
	bool within(float x, float a, float b) {
		return (x >= a) && (x <= b);
	}
virtual sf::Vector2f getposition(){}

	  virtual sf::Vector2f getsize() {}



protected:
	 virtual void draw(sf::RenderWindow & window) = 0;
		
};

