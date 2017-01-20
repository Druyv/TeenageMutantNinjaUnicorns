#pragma once
#include "image.hpp"


/*!
 * \class bullet
 *
 * \brief class that shoots bullet
 *
 * This class is used by mobs and the 
 * unicorn to fire a bullet when needed
 *
 * \author Jip Galema
 * \date 20-01-2017
 */
class bullet : public drawable
{
private:
	image_from_file image_bullet;
public:
	/*!
 	* \brief constructor that is used to initialize the bullet
 	*
 	* This constructor is used to initialize the position and 
 	* look of the bullet 
 	*
 	* \param[in] position 	position that the bullet is placed
 	* \param[in] image_name	filename of the image used as bullet
 	* 
 	*/
	bullet(sf::Vector2f position, std::string image_name);
	~bullet();

	/*!
 	* \brief function that draws the bullet
 	*
 	* This function overrides the draw function from drawable
 	* and draws the bullet on given window (parameter window)
 	*
 	* \param[in] window 	sf::RenderWindow from SFML that is used to draw on
 	* 
 	*/
	void draw(sf::RenderWindow & window) override;

	/*!
 	* \brief function that moves bullet
 	*
 	* Function that moves bullet through screen, checks
 	* if there is an collision, when there is the object destoys itself
 	*
 	*/
	void projectile();

	/*!
 	* \brief places bullet on spot given with parameter
 	*
 	* This function is used to set position for the bullet
 	*
 	* \param[in] position sf::Vector2f from SFML that is the new position
 	* 
 	*/
	void fire(sf::Vector2f fire_position);

};

