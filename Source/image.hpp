///@file

#ifndef IMAGE_HPP
#define IMAGE_HPP

#include <SFML/System/Vector2.hpp>

#include "drawable.hpp"

/// \class image_load_error
///
/// \brief image load error
///
/// This class is used to generate a image load error exception.
/// It inherrits the std::exception class so it can be easily caught
/// with an try catch block.
///
/// \date 19-1-2017
class image_load_error : public std::exception {
    public:
        /// \brief constructor
        ///
        /// This constructor puts a message into a string and saves that as
        /// a private variable. The image name is also added to the string.
        ///
        /// \param[in] image_name The name of the image
        image_load_error(const std::string & image_name) :
            msg{ std::string{ "Can not load image with name: " } + image_name }
        {}

        /// \brief return message
        ///
        /// This function returns the message so it can be printed.
        /// It overrides the what function from the std::exception
        /// superclass, making it easy to capture. 
        /// 
        /// \retval const char * {The error message as a const char *}
        const char * what() const noexcept override{
            return msg.c_str();
        }
    private:
        std::string msg;
    };

/// \class image_from_file
///
/// \brief create sprite on screen
///
///This class creates an sprite with an image as texture. The class inherrits the
/// superclass drawable. 
///
/// \sa drawable::
/// \sa sf::Sprite
/// \sa sf::Texture
/// \date 18-1-2017
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
        /// \sa image_load_error::
        /// \warning Make sure you use a Try catch block to capture the exception generated if the image cannot be loaded
        image_from_file(sf::Vector2f position, std::string image_name);

        /// \brief draw object
        ///
        /// This function is used for calling the draw function on the sfml object
        /// created within this class. It also sets the position for before it draws
        /// the object. This way if the position changes, it also changes on screen.
        ///
        /// \param[in,out] window The render window to draw the object on
        /// \sa sf::Sprite::draw()
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
        /// \sa sf::Sprite::getGlobalBounds()
        sf::FloatRect getGlobalBounds() override;
        
        sf::Vector2f get_position();
        sf::Vector2f get_size();
        void set_position(sf::Vector2f new_position);
        void set_size(sf::Vector2f new_size);
        
        void scale(sf::Vector2f scale_val);
        
};

#endif //IMAGE_HPP
