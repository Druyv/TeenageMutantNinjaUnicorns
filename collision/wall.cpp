#include <SFML/Graphics.hpp>
#include "wall.hpp"

wall::wall(sf::Vector2f position, sf::Vector2f size):
	position{ position },
	size{ size }
{}

void wall::draw(sf::RenderWindow & window)  {
	sf::RectangleShape rectangle;
	rectangle.setPosition(position);
	rectangle.setSize(size);
	rectangle.setFillColor(sf::Color::Red);
	window.draw(rectangle);

}


sf::Vector2f wall::getposition() {
	return position;
}

sf::Vector2f wall::getsize() {
	return size;
}

