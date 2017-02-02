///@file

#ifndef CAMERA_HPP
#define CAMERA_HPP

#include <SFML/Graphics.hpp>
#include <iostream>

#include "drawable.hpp"

///\class camera
///
/// \brief object folowing camera
/// 
/// This class can be used to follow a specific drawable object with the camera.
/// If the object moves the camera moves with it.
///
class camera{
    public:
	/// \brief constructor object
	///
	/// Constructor to make a camera that follows the player. 
	///
	/// \param[in] object The object to follow
	///
	camera(object_ptr object);

	/// \brief folow in render window
	///
	/// Follow the player in a specified render window.
	///
	/// \param[in] window SFML window that is used to display the camera.
	///
	void follow(sf::RenderWindow &window);
    private:
	object_ptr object;
	sf::View player_cam;
};
#endif //CAMERA_HPP
