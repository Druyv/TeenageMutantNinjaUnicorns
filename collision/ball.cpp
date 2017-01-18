#include <SFML/Graphics.hpp>
#include "ball.hpp"
#include <iostream>
ball::ball(sf::Vector2f position,sf::Vector2f speed, float size) :
	position{ position },
	speed{speed},
	size{size}
{}
void ball::draw( sf::RenderWindow & window )  {
	sf::CircleShape circle;
	circle.setRadius(size);
	circle.setPosition(position);
	circle.setFillColor(sf::Color::Blue);
	window.draw(circle);
}
void ball::automove() {
	position += speed;
}




sf::Vector2f ball::getposition() {
	return position;
}

sf::Vector2f ball::getsize()
{
	return sf::Vector2f();
}



bool ball::collaps2(sf::Vector2f position2, sf::Vector2f size_b) {
	if (within(position.x, position2.x, position2.x + size_b.x) and( (position.y == position2.y-(2 * (size))) or (position.y == position2.y+size_b.y)	)) {
		speed = sf::Vector2f(speed.x, -speed.y);
		return true;
	}
	else if (within(position.y, position2.y , position2.y + size_b.y ) && ((position.x == position2.x-(2 * (size))) or  (position.x == position2.x+size_b.x)) ){
		speed = sf::Vector2f(-speed.x, speed.y);
		return true;
	}
	return false;


}
