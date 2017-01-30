#pragma once
#include "drawable.hpp"
#include "image.hpp"

class mob;
/// a shared pointer to a mob object that is re-usable
typedef std::shared_ptr<mob> mob_ptr;

///
/// \class mob
///
/// \brief class that makes an enemy to play agianst 
///
/// This class creates an enemy that the player can shoot
/// this version doesn't include physics for the mob. It also 
/// can't fire back.
///
/// \date 26-01-2017
///
class mob : public drawable {
private:
	image_from_file mob_animation;
	bool alive = true;
public:

	///
	/// \brief constructor to initialize mob
	///
	/// This constructor is used to give a position and a name of the file used a image
	///
	/// \param[in] position	sf::Vector2f position where image is placed
	/// \param[in] filename	std::string that is the filename of the image used
	///
	///
	mob(sf::Vector2f position, std::string filename);

	///
	/// \brief draw function for mob
	///
	/// This function draws the mob_animation. It only draws the mob when 
	/// it is alive. This can be seen with the #mob::get_live() function
	///
	/// \param[in]	window	sf::RenderWindow that is used to draw picture on
	///
	///
	void draw(sf::RenderWindow & window) override;

	///
	/// \brief get function for global bounds
	///
	/// This function gets the global bounds of the image in mob. When the 
	/// mob is not alive gives a empty sf::FloatRect so bullet can't "accidentally"
	/// collide with the mob
	///
	/// \return sf::FloatRect that is empty when mob is not alive
	///
	sf::FloatRect getGlobalBounds() override;

	///
	/// \brief function that sets boolean
	/// 
	/// This function sets variable alive to false
	///
	void die();

	///
	/// \brief function that sets boolean
	///
	/// This function sets variable alive to true
	///
	void revive();

	///
	/// \brief function that returns alive variable
	///
	/// This function is used to return the current state of the boolean alive
	///
	/// \return boolean that gives information on if a mob is alive.
	///
	bool get_live();

};
