#ifndef DRAWABLE_HPP
#define DRAWABLE_HPP

#include <SFML/Graphics.hpp>

/*!
 * \class drawable
 *
 * \brief class that is inherited by all objects that are drawable
 *
 * class with a position, size and name, that is inherited by all 
 * object that can be drawn on the screen. 
 *
 * \author Jip Galema
 * \date 18/01/17
 */
class drawable {
protected:
	sf::Vector2f position;
	sf::Vector2f size;
	std::string name;
public:
	/*! drawable(const sf::Vector2f & position, const sf::Vector2f & size, std::string name)
	* \brief constructor for a drawable
	*
	* constructor that initializes position, size and name of drawable
	*
	* \param[in] position		position of drawable, this is a sf::Vector2f and const
	* \param[in] size			size of drawable, this is a sf::Vector2f and const
	* \param[in] name			this is the name of the drawable and is an std::string
	*/
	drawable(const sf::Vector2f & position, const sf::Vector2f & size, std::string name);

	/*! virtual void draw(sf::RenderWindow & window)
	* \brief virtual draw function for a drawable
	*
	* virtual function that is defined in the subclasses of drawable
	*
	* \param[in] window			SFML window that is used to display the drawable 
	*/
	virtual void draw(sf::RenderWindow & window) = 0;

	/*! virtual void move(sf::RenderWindow & delta)
	* \brief move function for a drawable
	*
	* function that moves the drawable with a certian delta
	*
	* \param[in] delta			sf::Vector2f that determines with what verctor the drawable is moves
	*/
	virtual void move(sf::Vector2f delta);
	
	/*! virtual void jump(sf::Vector2f new_location);
	* \brief virtual draw function for a drawable
	*
	* virtual function that changes position of drawable to new location given
	*
	* \param[in] new_location	sf::Vector2f that is used as new position of drawable
	*/
	virtual void jump(sf::Vector2f new_location);
     
	/*! virtual sf::FloatRect getGlobalBounds();
	* \brief virtual getGlobalBounds function 
	*
	* virtual function that gives sf::Floatrect of perimeter from the drawable
	*
	*/
	virtual sf::FloatRect getGlobalBounds() = 0;

	//Hier even doxygen toevoegen!!!!

	/*!
	* \brief [brief description]
	*
	* [detailed description]
	*
	* \param[in] [name of input parameter] [its description]
	* \param[out] [name of output parameter] [its description]
	* \return [information about return value]
	* \sa [see also section]
	* \note [any note about the function you might have]
	* \warning [any warning if necessary]
	*/
	virtual char collision(drawable & other);
};
#endif // DRAWABLE_HPP
