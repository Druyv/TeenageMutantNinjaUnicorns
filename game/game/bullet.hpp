///@file

#ifndef BULLET_HPP
#define BULLET_HPP

#include "drawable.hpp"
#include "image.hpp"
#include "npc.hpp"

///
/// \class bullet
///
/// \brief class calculates projectile to kill mobs 
///
/// This class is used to calculate a projectile that 
/// can kill mobs (if there hit by the object) 
///
/// \date 26-01-2017
///
class bullet : public drawable {
private:
	image_from_file bullet_animation;
	std::vector<mob_ptr> & all_mobs;
	objects_vector & objects;
	bool hit = false;
	//bool going_left;
	sf::Vector2f current_offset;

	/// 
	/// \brief function that moves bullet with offset
	/// 
	/// This function moves bullet_animation with given
	/// offset (a.k.a. current_offset)
	///
	void projectile();
public:
	///
	/// \brief constructor to initialize the bullet
	///
	/// This constructor intializes the position and picture used for the 
	/// bullet. It also receives two std::vectors, one vector for all mobs in
	/// the level, the other for all walls in the level
	///
	/// \param[in]	position	sf::Vector2f position where the bullet is placed
	/// \param[in]	filename	std::string that is the filename of the image used
	/// \param[in]	all_mobs	std::vector with mob shared_pointers to all mobs in the level
	/// \param[in]	objects		std::vector with drawable shared_pointers to all walls/obstacles in the level
	///
	///
	bullet(sf::Vector2f position, std::string filename, std::vector<mob_ptr> & all_mobs, objects_vector & objects);

	///
	/// \brief funtion that draws image
	///
	/// This function draws the bullet. This function checkes if the bullet is correctly scaled 
	/// depending on the direction it is fired. It only draws the bullet when boolean hit is false
	/// this happens when a bullet hasn't hit a object. 
	///
	/// \param[in]	window		sf::Renderwindow that is used to display the window on
	///
	///
	void draw(sf::RenderWindow & window) override;

	///
	/// \brief function that gets the globalbounds of the bullet_animation
	///
	/// This function gets the globalbounds of the bullet_animation. The globalbounds
	/// is the rectangle around the image.
	///
	/// \return	sf::FloatRect around the image
	sf::FloatRect getGlobalBounds() override;

	///
	/// \brief function that checks collision with pointer
	///
	/// This function checks if there is collision with either a mob or a wall
	/// and sets the boolean hit on true when collision with given object is found
	/// otherwide hit is set to false
	///
	/// \param[in]	unique_object	shared_pointer or pointer that gives location of object 
	///								that contains a getGlobalBounds function
	///
	template<typename P>
	void collision(P unique_object);

	///
	/// \brief function that manages moving the bullet and checking for collision
	///
	/// This function moves bullet with #bullet::projectile() function and then checks for 
	/// collisions with mobs and walls. If fire_position is not entered the bullet moves from its 
	/// last position. When offset is not entered it usually means the bullet is fired and still on the move
	/// in that case the current offset is used to make sure the bullet doesn't follow the unicorn
	///
	/// \param[in]	window			sf::RenderWindow that is used to display the bullet
	/// \param[in]	shoot_timeout	int given by reference that is used to reset the shot, when something hits the bullet
	/// \param[in]	offset			sf::Vector2f for movement, has negative x-coordinate when fired to left side
	/// \param[in]	fire_position	sf::Vector2f for position for bullet to start projectile. 
	///
	void shoot(sf::RenderWindow & window, int & shoot_timeout, sf::Vector2f offset = sf::Vector2f(0, 0), sf::Vector2f fire_position = sf::Vector2f(0.0, 0.0));
        
        void set_position(sf::Vector2f new_position);
        
};

#endif //BULLET_HPP
