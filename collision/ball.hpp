#ifndef _BALL_HPP
#define _BALL_HPP

#include <SFML/Graphics.hpp>
#include "super.hpp"
#include "wall.hpp"
#include "rectangle.hpp"


class ball: public super {
public:

	ball( sf::Vector2f position,sf::Vector2f speed, float size = 30.0);

	void draw( sf::RenderWindow & window ) override;
	
	void automove();

	bool collaps2(sf::Vector2f position2, sf::Vector2f size);
	sf::Vector2f getposition() override;
	sf::Vector2f getsize()override;


private:
	sf::Vector2f position;
	float size;
	sf::Vector2f speed;

};

#endif
