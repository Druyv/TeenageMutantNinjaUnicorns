///@file

#ifndef UNICORN_HPP
#define UNICORN_HPP

#include "drawable.hpp"
#include "image.hpp"
#include <iostream>


///
/// \class unicorn
///
/// \brief class that is used to display and control the unicorn
///
/// This class is used to control the unicorn and can be used to
/// control it aswell (moving around and jumping. This class
/// inherents the drawable class and has an object of the image_from_file
/// class.
///
/// \date 19-01-2017
///
class unicorn : public drawable {
private:
	bool going_left = false;
	bool correctly_scaled = false;
	int jump_counter = 0;
	actions & actions_array;
	image_from_file unicorn_animation;
	physics physics_object;
	collisions & the_collisions;
        sf::Vector2f spawn_location;
public:
	/// \brief Constructor to initialize the unicorn
	///
	/// This construcor initializes the position of the unicorn
	/// as well a the filename of the image used
	///
	/// \param[in] position	Position where the image is placed
	/// \param[in] filename	The filename of the image
        /// \param[in] actions_array The actions of the unicorn
        /// \param[in] the_collisions The collisions the unicorn has
	///
	unicorn(sf::Vector2f position, std::string filename, actions & actions_array, collisions & the_collisions);

	/// \brief function that draws the image
	///
	/// this function draws the unicorn, depending on the unicorn going left or rigth
	/// scales the image (if it isn't already correctly scaled)
	///
	/// \param[in] window SFML window that is used to display the image
	///
	void draw(sf::RenderWindow & window) override;

	/// \brief function that moves image object with a certian delta
	///
	/// This function moves the image with a certian vector. This vector
	/// is the parameter delta
	///
	/// \param[in] delta		sf::Vector2f that determines movement
	///
	/// \sa https://www.sfml-dev.org/documentation/2.0/classsf_1_1Transformable.php#ab9ca691522f6ddc1a40406849b87c469
	///
	void move(sf::Vector2f delta) override;


	/// \brief let the unicorn jump
	///
	/// This function allows the unicorn to jump if it is not already jumping
	/// and if the unicorn is standing on the ground.
	///
	/// \sa sf::Sprite::getGlobalBounds()
        ///
	void jump() override;

	///
	/// \brief function that gets the boundingbox of the image
	///
	/// This function gets the boundingbox of the image and returns
	/// this.
	///
	/// \return wich are the boundaries of the image
	///
	sf::FloatRect getGlobalBounds() override;

	///
	/// \brief functions that runs through all actions related to the unicorn
	///
	/// This function contains for-loop that runs through actions for this
	/// unicorn
	///
	void run_actions(object_ptr object) override;

	/// \brief Check the collisions vector
	///
	/// This function checks the collisions vector for a collision
	/// where the c is the direction. When c is 'U' it checks the U
	/// value of the collisions struct.
	///
	/// \param[in] c The character to check for
	///
	collision check_for_collisions(char c) override;

	//----------------------------------------------
	//
	//experimental
	//
	//----------------------------------------------
	void shoot(sf::Vector2f fire_position);

        /// \brief set the spawn location
	///
	/// This function sets the spawn location of the unicorn to a new
        /// location. The unicorn will spawn in the new location if he dies.
	///
	/// \param[in] new_location The new spawn location for the unicorn
        ///
	void set_spawn_location(sf::Vector2f new_location);
};
#endif //UNICORN_HPP