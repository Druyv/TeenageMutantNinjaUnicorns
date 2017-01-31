///@file

#ifndef _BACKGROUND_HPP
#define _BACKGROUND_HPP


#include <SFML/Graphics.hpp>
#include <string>
#include "drawable.hpp"
#include "image.hpp"


/// \class Background
///
/// \brief Class that draws a background
///
/// class with a position, size and name, that is inherited by all
/// object that can be drawn on the screen.
///
/// \date 23/01/17
///
class background : public drawable {
public:
	/// \brief constructor for background class
	///
	/// constructor that initializes the file that the background class will use. Default is "x", if default a default picture will be loaded.
	///
	/// \param[in] std::string name of the .png file that will be loaded as a background
        ///
	background(std::string filename, sf::Vector2f level_size);
        
	/// \brief Draw function for background class
	///
	/// defines draw function in super class. Draws the background.
	///
	/// \param[in] window SFML window that is used to display the drawable
	///
	void draw(sf::RenderWindow &window) override;
        
	/// \brief Get the global bounds
	///
	/// This function returns the global bounds of the #background_image.
        /// Those global bounds can be used for things like checking collisions.
	///
	/// \return The global bounds of the #background_image
	///
        sf::FloatRect getGlobalBounds() override;
private:
	image_from_file background_image; 
};
#endif	
