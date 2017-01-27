#ifndef _MENU1_HPP
#define _MENU1_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include "drawable.hpp"
#include "background.hpp"
#include "button.hpp"



class menu {
private:
	sf::RenderWindow & window;
	std::string background_picture;
	bool button_bool1;
	bool button_bool2;
	bool button_bool3;

	std::string button_one_text;
	std::string button_two_text;
	std::string button_three_text;

	Button button1;
	Button button2;
	Button button3;

	//background bg;
public:
	menu(sf::RenderWindow & window, std::string background_picture, bool button_bool1, std::string button_one_text,
	bool button_bool2 = 0, std::string button_two_text = "Empty", bool button_bool3 = 0, std::string button_three_text = "Empty");

	void build_menu();
	int select(sf::Vector2i position);





};



#endif
