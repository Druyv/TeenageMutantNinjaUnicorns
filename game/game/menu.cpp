#include "menu.hpp"	
#include "button.hpp"

menu::menu(sf::RenderWindow & window, std::string backgroud_picture, bool button_bool1, std::string button_one_text,
	bool button_bool2, std::string button_two_text, bool button_bool3, std::string button_three_text) :

	window(window),
	background_picture(background_picture),
	button_bool1(button_bool1),
	button_one_text(button_one_text),
	button_bool2(button_bool2),
	button_two_text(button_two_text),
	button_bool3(button_bool3),
	button_three_text(button_three_text),
	button1(float(window.getSize().y), float(window.getSize().x), 1, button_one_text),
	button2(float(window.getSize().y), float(window.getSize().x), 2, button_two_text),
	button3(float(window.getSize().y), float(window.getSize().x), 3, button_three_text)
	//bg(background(background_picture, sf::Vector2f( 1900, 800)))
{
}



void menu::build_menu() {
	//bg.draw(window);

	if (button_bool1) {
		button1.draw(window);
	};
	if (button_bool2) {
		button2.draw(window);
	};
	if (button_bool3) {
		button3.draw(window);
	};

};



int menu::select(sf::Vector2i position) {
	sf::Vector2f point = sf::Vector2f(static_cast<float>(position.x), static_cast<float>(position.y));

	if ((button1.getGlobalBounds()).contains(point) && button_bool1)
	{
		return 1;
	}
	if ((button2.getGlobalBounds()).contains(point) && button_bool2)
	{
		return 2;
	}
	if ((button3.getGlobalBounds()).contains(point) && button_bool3)
	{
		return 3;
	}
	return -1;
};


int menu::last_button() {
	if (button_bool1) {
		if (!button_bool2) {
			return 1;
		}
		else {
			if (!button_bool3) {
				return 2;
			}
			else {
				return 3;
			}
		}
	}
	else {
		return 0;
	}
}

std::string menu::get_button_text(int button_place) {
	if (button_place == 1) {
		return button_one_text;
	}
	else if (button_place == 2) {
		return button_two_text;
	}
	else if (button_place == 3) {
		return button_three_text;
	}
	else {
		return "";
	}
}
