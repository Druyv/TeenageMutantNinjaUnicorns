#include <SFML/Graphics.hpp>
#include "ball.hpp"
#include <iostream>
ball::ball(sf::Vector2f position, sf::Vector2f size) :
    
	super(position,size)
	
	
{}
void ball::draw( sf::RenderWindow & window )  {
	sf::RectangleShape circle;
	circle.setSize(size);
	circle.setPosition(position);
	circle.setFillColor(sf::Color::Blue);
	window.draw(circle);
}






