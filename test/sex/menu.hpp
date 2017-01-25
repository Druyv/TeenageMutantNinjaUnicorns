#ifndef _MENU_HPP
#define _MENU_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include "drawable.hpp"

class Menu:public drawable {
private:
	int selectedItemIndex;
	sf::Font font;
	sf::Text menu[MAX_NUMBER_OF_ITEMS];
public:
	Menu(float width, float height);
	~Menu();

	void draw(sf::RenderWindow &window);
	void MoveUp();
	void MoveDown();
	int GetPressedItem() { return selectedItemIndex; }



};



#endif
