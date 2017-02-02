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
	soundtrack & sound;
	textbox textbox1;
	textbox textbox2;
	textbox textbox3;
	textbox textbox4;
	textbox textbox5;
	textbox textbox6;
	textbox textbox7;
	textbox textbox8;
	textbox textbox9;
    textbox textbox_cyan1;
    textbox textbox_cyan2;
    textbox textbox_cyan3;
    textbox textbox_cyan4;
    textbox textbox_cyan5;
    textbox textbox_cyan6;
    textbox textbox_cyan7;
    image_from_file background_cyan;
	image_from_file background_angryarno;
	image_from_file background_zoomedin;
	image_from_file background_construction;
	image_from_file background_forest;
	image_from_file Arno;
	image_from_file Junior;


public:
	cutscene1(sf::RenderWindow & window,soundtrack & sound);

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
	void scene11();
	void scene12();
	void scene13();
	void scene14();
	void scene15();
	void scene16();
	void scene17();
    void cyan_island();
    
};

#endif
