///@file


/*!
* \file textbox.hpp
*
* \author Luke Roovers
* \date	27-1-2017
*
* Textbox class
*/

#ifndef _cutscene1_HPP
#define _cutscene1_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include "background.hpp"
#include "soundtrack.hpp"
#include "textbox.hpp"
#include "image.hpp"

class cutscene1 {
private:
	sf::RenderWindow & window;
	textbox textbox1;
	textbox textbox2;
	textbox textbox3;
	textbox textbox4;
	textbox textbox5;
	textbox textbox6;
	textbox textbox7;
	textbox textbox8;
	textbox textbox9;
	image_from_file background_angryarno;
	image_from_file background_zoomedin;
	image_from_file background_construction;
	image_from_file background_forest;
	image_from_file Arno;
	image_from_file Junior;


public:
	cutscene1(sf::RenderWindow & window);

	void play_scene();
	void scene1();
	void scene2();
	void scene3();
	void scene4();
	void scene5();
	void scene6();
	void scene7();
	void scene8();
	void scene9();
	void scene10();

};

#endif
