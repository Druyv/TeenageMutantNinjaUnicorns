///@file

/*!
* \file Background.hpp
*
* \author Luke Roovers
* \date	23-1-2017
*
* Background class
*/

#ifndef _BACKGROUND_HPP
#define _BACKGROUND_HPP

#include "drawable.hpp"
#include <SFML\Graphics.hpp>
#include <iostream>
#include <string>

/*!
* \class Background
*
* \brief Class that draws a background
*
* class with a position, size and name, that is inherited by all
* object that can be drawn on the screen.
*
* \date 23/01/17
*/
class Background:public drawable
{
public:
	/*! drawable(std::string str = "x")
	* \brief constructor for background class
	*
	* constructor that initializes the file that the background class will use. Default is "x", if default a default picture will be loaded.
	*
	* \param[in] str		name of the .png file that will be loaded as a background, this is a sf::Vector2f
	*/
	Background(std::string filename);
	/*!void draw(sf::RenderWindow & window) override
	* \brief Draw function for background class
	*
	* defines draw function in super class. Draws the background.
	*
	* \param[in] window			SFML window that is used to display the drawable
	*/
	void draw(sf::RenderWindow &window) override;
	
	sf::FloatRect getGlobalBounds() override;
private:
	sf::Texture background_texture;
	sf::Sprite background_sprite;
	std::string filename;
};
#endif	
