#include <SFML/Graphics.hpp>
#include "rectangle.hpp"

rectangle::rectangle(sf::Vector2f position, sf::Vector2f size):
	position{ position },
	size{ size }
{}
void rectangle::draw(sf::RenderWindow & window)  {
	sf::RectangleShape rectangle;
	rectangle.setPosition(position);
	rectangle.setSize(size);
	rectangle.setFillColor(sf::Color(100,100,100));
	window.draw(rectangle);
}
void rectangle::move(sf::Vector2f delta) {
	position += delta;
}
void rectangle::jump(sf::Vector2f target) {
	position = target;
}
void rectangle::jump(sf::Vector2i target) {
	jump(sf::Vector2f(
		static_cast< float >(target.x),
		static_cast< float >(target.y)
	));
}

sf::Vector2f rectangle::getposition() {
	return position;
}

sf::Vector2f rectangle::getsize() {
	return size;
}

