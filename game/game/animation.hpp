///@file

#ifndef ANIMATION_HPP
#define ANIMATION_HPP

#include <memory>

#include "SFML/Graphics.hpp"
#include "drawable.hpp"
#include "exceptions.hpp" 

/// \class animation
///
/// \brief create sprite on screen with animations
///
///This class creates a sprite with an image as texture. The image contains all needed images for the animations of that object.
///
/// \sa drawable
/// \sa <a href="https://www.sfml-dev.org/documentation/2.0/classsf_1_1Sprite.php ">sf::Sprite</a>
/// \sa <a href="https://www.sfml-dev.org/documentation/2.0/classsf_1_1Texture.php">sf::Texture</a>
class animation : public drawable {
    private:
	sf::Sprite sheet;
	std::string sheet_name;
	sf::Texture texture;
        float count=0;
        float row=0;
        float  rot=0;
        bool is_jumping = false;
        bool rotate = false;

    public:
	/// \brief constructor
	///
	/// The constructor tries to load an sheet with the sheet name specified.
	/// If it cannot load the image it generates an exception that can be caught
	/// with an try, catch block. 
	///
	/// \param[in] position The objects initial position
	/// \param[in] image_name The name of the image that has to be loaded
	/// \sa sheet_load_error
	/// \warning Make sure you use a Try catch block to capture the exception generated, if the image cannot be loaded
	animation(sf::Vector2f position, std::string sheet_name, float width,float length);
        
	/// \brief draw object
	///
	/// This function is used for calling the draw function on the sfml object
	/// created within this class. It also sets the position for the object before it draws
	/// the object. This way if the position changes, it also changes on screen.
	///
	/// \param[in,out] window The render window to draw the object on
	void draw(sf::RenderWindow & window) override;
        
	/// \brief get objects floatrect
	///
	/// This function uses the getGlobalBounds function from the object to get the
	/// bounding box of the object. It returns this as a floatrect. This return value
	/// can be used to check if the object touches another object.
	///
	/// \param[in] position The objects initial position
	/// \param[in] image_name The name of the image that has to be loaded
	/// \retval sf::FloatRect {The bounding box of the sprite object created in this class}
	sf::FloatRect getGlobalBounds() override;

	/// \brief set position
	///
	/// This function sets the position of the object to a new value.
	///
	/// \param[in] new_position sf::Vector2f The position we want to move the object to
	/// \sa <a href="https://www.sfml-dev.org/documentation/2.0/classsf_1_1Vector2.php ">sf::Vector2f</a>
	void set_position(sf::Vector2f new_position);
        
	/// \brief set size
	///
	/// This function sets the size of the object.
	///
	/// \param[in] new_size sf::Vector2f The size we want to set the object to
	/// \sa <a href="https://www.sfml-dev.org/documentation/2.0/classsf_1_1Vector2.php ">sf::Vector2f</a>
	void set_size(sf::Vector2f new_size);
        
	/// \brief 
	///
	/// This function for animations  
	///
	/// \param[in] row_a  int indicator for which  animation is needed
	/// 
        bool movement(float row_a, int level_counter = 0);

	/// \brief set the texture rectangle
	///
	/// This function can be used to turn the object around
	/// while keeping the same upper left corner as the position
	/// of the object.
	///
	/// \param[in] rectangle const sf::IntRect& The rectangle box to turn around
	/// \sa <a href="https://www.sfml-dev.org/documentation/2.0/classsf_1_1Sprite.php#a3fefec419a4e6a90c0fd54c793d82ec2 ">sf::Sprite::setTextureRect sf::IntRect</a>
	void setTextureRect(const sf::IntRect & rectangle);
};
#endif //ANIMATION_HPP
