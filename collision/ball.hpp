#ifndef _BALL_HPP
#define _BALL_HPP

#include <SFML/Graphics.hpp>
#include "drawable.hpp"
#include "wall.hpp"
#include <math.h>
#include <iostream>

#include <vector>
class ball: public drawable {
public:
    ball():
        drawable()
        {}
        
	ball( sf::Vector2f position,sf::Vector2f size, std::vector<action> actionlist={});
   
	void draw( sf::RenderWindow & window ) override;

	
    
 
	
	


private:
	
	
	

};

#endif
