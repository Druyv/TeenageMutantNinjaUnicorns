///@file

#ifndef IMAGE_HPP
#define IMAGE_HPP

#include "drawable.hpp"
#include "exceptions.hpp"

/// \class image_from_file
///
/// \brief create sprite on screen
///
///This class creates an sprite with an image as texture. The class inherrits the
/// superclass drawable. 
///
/// \sa drawable
/// \sa <a href="https://www.sfml-dev.org/documentation/2.0/classsf_1_1Sprite.php ">sf::Sprite</a>
/// \sa <a href="https://www.sfml-dev.org/documentation/2.0/classsf_1_1Texture.php">sf::Texture</a>
///
class image_from_file : public drawable {
private:
	sf::Sprite image;
	std::string image_name;
	sf::Texture texture;
public:
	/// \brief constructor
	///
	/// The constructor tries to load an image with the image name specified.
	/// If it can not load the image it generates an exception that can be caught
	/// with an try, catch block. 
	///
	/// \param[in] position The objects initial position
	/// \param[in] image_name The name of the image that has to be loaded
	/// \sa image_load_error
	/// \warning Make sure you use a Try catch block to capture the exception generated if the image cannot be loaded
        ///
	image_from_file(sf::Vector2f position, std::string image_name);

	/// \brief draw object
	///
	/// This function is used for calling the draw function on the sfml object
	/// created within this class. It also sets the position for before it draws
	/// the object. This way if the position changes, it also changes on screen.
	///
	/// \param[in,out] window The render window to draw the object on
        ///
	void draw(sf::RenderWindow & window) override;

	/// \brief get objects floatrect
	///
	/// This function uses the getGlobalBounds function from te object to get the
	/// bounding box of the object. It returns this as a floatrect. This return value
	/// can be used to check if the object touches another object.
	///
	/// \param[in] position The objects initial position
	/// \param[in] image_name The name of the image that has to be loaded
	/// \retval sf::FloatRect {The bounding box of the sprite object created in this class}
        ///
	sf::FloatRect getGlobalBounds() override;

	/// \brief set position
	///
	/// This function sets the position of the object to a new value.
	///
	/// \param[in] new_position sf::Vector2f The position we want to move the object to
	/// \sa <a href="https://www.sfml-dev.org/documentation/2.0/classsf_1_1Vector2.php ">sf::Vector2f</a>
        ///
	void set_position(sf::Vector2f new_position);

	/// \brief set size
	///
	/// This function sets the size of the object.
	///
	/// \param[in] new_size sf::Vector2f The size we want to set the object to
	/// \sa <a href="https://www.sfml-dev.org/documentation/2.0/classsf_1_1Vector2.php ">sf::Vector2f</a>
        ///
	void set_size(sf::Vector2f new_size);

	/// \brief set the texture rectangle
	///
	/// This function can be used to turn the object around
	/// while keeping the same upper left corner as the position
	/// of the object.
	///
	/// \param[in] rectangle const sf::IntRect& The rectangle box to turn around
	/// \sa <a href="https://www.sfml-dev.org/documentation/2.0/classsf_1_1Sprite.php#a3fefec419a4e6a90c0fd54c793d82ec2 ">sf::Sprite::setTextureRect sf::IntRect</a>
        ///
	void setTextureRect(const sf::IntRect & rectangle);
        
        /// \brief Set smooth
	///
	/// This function can be used to make the image lines more smooth.
	///
	/// \param[in] smooth Boolean for either making the lines smooth or not
        ///
        void set_smooth(bool smooth);
        
        /// \brief Set repeated
	///
	/// This function can be used to make the image repeat itself if the
        /// size of the image is smaller then the object.
	///
	/// \param[in] repeated Boolean for either making the image repeat itself or not
        ///
        void set_repeated(bool repeated);
        
        /// \brief Set scale
	///
	/// This function can be used to scale the image
	///
	/// \param[in] x The scale factor for the x of the image
        /// \param[in] y The scale factor for the y of the image
        ///
        void set_scale(float x, float y);
};

#endif //IMAGE_HPP
