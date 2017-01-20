///@file

#ifndef UNICORN_HPP
#define UNICORN_HPP

#include "drawable.hpp"
#include "image.hpp"


/*!
* \class unicorn
*
* \brief class that is used to display and control the unicorn
*
* This class is used to control the unicorn and can be used to 
* control it aswell (moving around and jumping. This class 
* inherents the drawable class and has an object of the image_from_file
* class.
*
* \date 19-01-2017
*/
class unicorn : public drawable {
    private:
	bool going_left = false;
	bool correctly_scaled = false;
    protected:
	image_from_file unicorn_animation;
	action actions_array[2] = {
		action(sf::Keyboard::Left, [&] () {move(sf::Vector2f(-20.0,0.0)); going_left = true; }),// going_left = true; 
		action(sf::Keyboard::Right, [&]() {move(sf::Vector2f(20.0,0.0)); going_left = false; })// going_left = false; 
	};
    public:
	/*!
	* \brief constructor to initialize the unicorn
	*
	* This construcor initializes the position of the unicorn
	* as well a the filename of the image used 
	*
	* \param[in] position	sf::Vector2f position where the image is placed 
	* \param[in] filename	std::string that is the filename of the image used
	* 
	*/
	unicorn(sf::Vector2f position, std::string filename);

	/*!
	* \brief function that draws the image
	*
	* this function draws the unicorn, depending on the unicorn going left or rigth
	* scales the image (if it isn't already correctly scaled)
	*
	* \param[in] window		SFML window that is used to display the image
	*
	*/
	void draw(sf::RenderWindow & window) override;

	/*!
	* \brief function that moves image object with a certian delta
	*
	* This function moves the image with a certian vector. This vector
	* is the parameter delta
	*
	* \param[in] delta		sf::Vector2f that determines movement 
	*
	* \sa https://www.sfml-dev.org/documentation/2.0/classsf_1_1Transformable.php#ab9ca691522f6ddc1a40406849b87c469
	*
	*/
	void move(sf::Vector2f delta) override;

	/*!
	* \brief function that gets the boundingbox of the image
	*
	* This function gets the boundingbox of the image and returns 
	* this.
	*
	* \return sf::FloatRect wich are the boundaries of the image 
	*
	*/
	sf::FloatRect getGlobalBounds() override;

	/*!
	* \brief functions that runs through all actions related to the unicorn
	*
	* This function contains for-loop that runs through actions for this 
	* unicorn
	*
	*/
	void run_actions() override;

	/*!
 	* \brief function that shoots bullet from certian position
 	*
 	* This function creates a bullet-object and moves it from a given position 
 	* to a position where this bullet hits an object. 
 	* 
 	*
 	* \param[in] fire_position position from where the bullet gets fired
 	*
 	*/
	void shoot(sf::Vector2f fire_position);
};
#endif //UNICORN_HPP
