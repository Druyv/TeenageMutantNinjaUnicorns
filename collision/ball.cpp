#include <SFML/Graphics.hpp>
#include "ball.hpp"
#include <iostream>
ball::ball(sf::Vector2f position, sf::Vector2f size,std::vector<action> actionlist) :
    
	drawable(position,size,actionlist)
	
	
{}
void ball::draw( sf::RenderWindow & window )  {
	sf::RectangleShape circle;
	circle.setSize(size);
	circle.setPosition(position);
	circle.setFillColor(sf::Color::Blue);
	window.draw(circle);
    //std::cerr<< position .x<<","<<position.y<<"\n";
}






