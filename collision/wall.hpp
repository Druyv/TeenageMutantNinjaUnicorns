
#ifndef _WALL_HPP
#define _WALL_HPP
#include "super.hpp"
#include <SFML/Graphics.hpp>
#include <vector>
#include "action.hpp"
class wall : public super  {
public:

	wall(sf::Vector2f position,sf::Vector2f size,std::vector<action> actionlist ={});

	void draw(sf::RenderWindow & window)override ;


private:
	



};

#endif
