#ifndef _BALL_HPP
#define _BALL_HPP

#include <SFML/Graphics.hpp>
#include "super.hpp"
#include "wall.hpp"



class ball: public super {
public:

	ball( sf::Vector2f position,sf::Vector2f size);

	void draw( sf::RenderWindow & window ) override;

	

	
	


private:
	
	
	

};

#endif
