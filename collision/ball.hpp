#ifndef _BALL_HPP
#define _BALL_HPP

#include <SFML/Graphics.hpp>
#include "super.hpp"
#include "wall.hpp"
#include <math.h>
#include <iostream>
#include "action.hpp"
#include <vector>
class ball: public super {
public:
    ball():
        super()
        {}
        
	ball( sf::Vector2f position,sf::Vector2f size, std::vector<action> actionlist={});
   
	void draw( sf::RenderWindow & window ) override;

	
    
 
	
	


private:
	
	
	

};

#endif
