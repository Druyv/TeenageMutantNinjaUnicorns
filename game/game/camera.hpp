///@file

#ifndef _CAMERA_HPP
#define _CAMERA_HPP
#include <SFML/Graphics.hpp>
#include <iostream>
#include "drawable.hpp"

///\class camera
///
/// \brief Class that creates a camera that follows the player around
///
/// class with a unicorn tracking function.
///
class camera{
public:
	
	/// \brief constructor for camera player
	///
	/// constructor to make a camera. 
	///
	/// \param[in] player		object that the camera will follow
	///
	camera(object_ptr Unicorn);

	/// \brief playercam 
	///
	/// Follow the player
	///
	/// \param[in] window			SFML window that is used to display the camera.
	///
	void follow(sf::RenderWindow &window);

private:
	object_ptr Unicorn;
	sf::View playerCam;
};
#endif
