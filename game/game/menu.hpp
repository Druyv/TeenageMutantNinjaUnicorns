///@file
#ifndef _MENU1_HPP
#define _MENU1_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include "drawable.hpp"
//#include "background.hpp"
#include "image.hpp"
#include "button.hpp"


/// \class menu
///
/// \brief Creates a menu with up to 3 buttons
///
///  This class consists of 3 #Button objects and a #Background object.
///  It creates a menu and also deals with the clickable part of it.
/// 
/// Note: We would like to transfer all the math from #Button over here.
/// However, this has low priority . 
///
/// \date 27-1-2017
class menu {
private:
	sf::RenderWindow & window;

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
        image_from_file background;
public:
	/// \brief constructor to make a menu
	///
	/// constructor to make a menu with 1 - 2  or  3 buttons. Also requires a 
	/// picture for the background. All buttons have default values, so you can specify 
	/// which buttons you want on the menu. 
	///  
	///
	/// \param[in] Window           RenderWindow 
	/// \param[in] bgPicture        Name and type ( .png ) to load background picture form
	/// \param[in] buttonBool1      Determines if button1 will be drawn
	/// \param[in] ButtonOneText    Text that will be displayed on button1
	/// \param[in] buttonBool2      Determines if button2 will be drawn
	/// \param[in] ButtonTwoText    Text that will be displayed on button2
	/// \param[in] buttonBool3      Determines if button3 will be drawn
	/// \param[in] ButtonThreeText  Text that will be displayed on button3
	menu(sf::RenderWindow & window, std::string  background_picture, bool button_bool1, std::string button_one_text,
	bool button_bool2 = 0, std::string button_two_text = "Empty", bool button_bool3 = 0, std::string button_three_text = "Empty");

	/// \brief Function to build and draw the menu
	///
	/// This function builds the menu, with the buttons that were specified in the constructor.
	/// It also handles the drawing of the buttons. 
	///
	void build_menu();

	/// \brief Function that handles the pushable part of the button 
	///
	/// This function checks if position is located inside the bounding boxes 
	/// of the buttons, if yes it will return either a 0 or a 1 or a 2, depending
	/// on which button was pushed. This allows different functionality for the three buttons. 
	///
	/// \param[in] position     The position of the mouse when the left mouse button is pushed
	int select(sf::Vector2i position);
	/// \rief Function that determines what the last button is 
	///
	/// This function is used to determine what the last button is in the menu
	/// returns number of last button in menu
	int last_button();
	/// \brief
	/// 
	/// getter for the name of the button equal to the button number
	///
	/// param[in]  button_place number of the button.

	std::string get_button_text(int button_place);



};



#endif
