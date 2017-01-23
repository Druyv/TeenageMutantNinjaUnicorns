#ifndef _WALL_HPP
#define _WALL_HPP
#include "drawable.hpp"


/*!
 * \class wall
 *
 * \brief class for walls and platforms 
 *
 *  This class can be used for making rectangle shapes used as wall or platform for walking on oras boundry.
 *
 * \date 23/01/17
 */
class wall : public drawable {
    public:
/*! wall(const sf::Vector2f & position, const sf::Vector2f & size, std::Color object_color)
	* \brief constructor for a wall
	*
	* constructor that initializes position, size and color of drawable
	*
	* \param[in] position		position of drawable, this is a sf::Vector2f and const
	* \param[in] size		size of drawable, this is a sf::Vector2f and const
	* \param[in] object_color		color of the wall, this is a sf::Color 	
*/

        wall(sf::Vector2f position, sf::Vector2f size, sf::Color object_color);
/*! 	void draw (sf::RenderWindow &window) override
	* \brief draw function for the wall.
	*
	* this function draw the wall to the render of the window. 
	*
	* \param[in] window		window, this is a sf::RenderWindow
*/
        void draw(sf::RenderWindow & window) override;
/*! 	sf::FloatRect getGlobalBounds() override
	* \brief function that gives de global bounds. 
	*
	* this function returns the globalbounds. 
	*
*/
        sf::FloatRect getGlobalBounds() override;
/*! 	std::string object_information() override
	* \brief funtion that returns object information. 
	*
	* this function returns  object information. 
*/
        std::string object_information() override;
    private:
        sf::Color object_color;
        sf::RectangleShape rectangle;
};

#endif //_WALL_HPP
