///@file


/*!
* \file textbox.hpp
*
* \author Luke Roovers
* \date	27-1-2017
*
* Textbox class
*/

#ifndef _textbox_HPP
#define _textbox_HPP

#include <SFML/Graphics.hpp>
#include <iostream>


class textbox {
private:
	sf::Text			text;
	std::string			string;
	std::string			filename;
	sf::Vector2f		position;
	sf::RectangleShape	BoxBackground;
	sf::RectangleShape	HeadBox;
	sf::Texture			texture;
	sf::Texture			texture2;
	sf::RenderWindow &	window;
	sf::Font			font;
public:
	textbox(std::string string,std::string filename,sf::RenderWindow & window);

	void build_box();
	void draw(sf::RenderWindow & window1);

};

#endif
