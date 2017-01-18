#pragma once
#include <SFML/Graphics.hpp>
#include "super.hpp"
class rectangle: public super {
public:

	rectangle(sf::Vector2f position, sf::Vector2f size); 

	void draw(sf::RenderWindow & window) override;
	void move(sf::Vector2f delta);
	void jump(sf::Vector2f target);
	void jump(sf::Vector2i target);
	sf::Vector2f getposition()override;
	sf::Vector2f getsize() override;


private:
	sf::Vector2f position;
	sf::Vector2f size;
};



