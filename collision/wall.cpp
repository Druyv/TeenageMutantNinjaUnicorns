#include <SFML/Graphics.hpp>
#include "wall.hpp"

wall::wall(sf::Vector2f position, sf::Vector2f size):
	super(position,size)
{}

void wall::draw(sf::RenderWindow & window)  {
	sf::RectangleShape rectangle;
	rectangle.setPosition(position);
	rectangle.setSize(size);
	rectangle.setFillColor(sf::Color::Red);
	window.draw(rectangle);

}


