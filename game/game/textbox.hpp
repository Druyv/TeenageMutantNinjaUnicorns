///@file

#ifndef TEXTBOX_HPP
#define TEXTBOX_HPP

#include <SFML/Graphics.hpp>
#include <iostream>

/// \class textbox
///
/// \brief Creates a box with text and a headshot
///
/// This class is used to make a textbox 
/// on the screen. It consists of text, the box and a 
/// severed unicorn head. 
///  
///
/// \date 2-2-2017
class textbox {
    private:
	sf::Text text;
	std::string string;
	std::string filename;
	sf::Vector2f position;
	sf::RectangleShape box_background;
	sf::RectangleShape head_box;
	sf::Texture texture;
	sf::Texture texture2;
	sf::RenderWindow & window;
	sf::Font font;
    public:
        /// \brief constructor to initialize a textbox
	///  
	///  The constructor uses the window size to   
	///  draw a textbox on the screen 
	///
	/// \param[in] string   Text that is displayed
	/// \param[in] filename filename of the severed unicorn head
	/// \param[in] window   sf::renderwindow object
	textbox(std::string string, std::string filename, sf::RenderWindow & window);
        
        /// \brief Draws the textbox
	///
        ///  everything needed to draw the textbox is in here.
	///  Some math is done to make sure its in the right position.
	///
	void build_box();
        
	/// \brief Draws the textbox
	///
        /// Draw function
        /// 
	void draw(sf::RenderWindow & window1);
};
#endif //TEXTBOX_HPP
