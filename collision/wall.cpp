#include <SFML/Graphics.hpp>
#include "wall.hpp"

wall::wall(sf::Vector2f position, sf::Vector2f size,std::vector<action> actionlist):
	super(position,size,actionlist)
{}

void wall::draw(sf::RenderWindow & window)  {
	sf::RectangleShape rectangle;
	rectangle.setPosition(position);
	rectangle.setSize(size);
	rectangle.setFillColor(sf::Color::Red);
	window.draw(rectangle);

}


