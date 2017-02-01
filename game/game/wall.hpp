
///@file
#ifndef _WALL_HPP
#define _WALL_HPP

#include "drawable.hpp"
#include "exceptions.hpp"

/// \class wall
///
/// \brief Class for walls and platforms 
///
/// This class can be used for making rectangle shapes used as wall or platform for walking on or as boundry.
///
///  \date 23/01/17
///
class wall : public drawable {
    public:
	///  \brief Constructor for a wall
	///
	/// Constructor that initializes position, size and color of drawable
	///
	/// \param[in] position Position of drawable, this is a sf::Vector2f and const
	/// \param[in] size Size of drawable, this is a sf::Vector2f and const
	/// \param[in] object_color Color of the wall, this is a sf::Color 
        /// \param[in] image_name An image to put inside the wall. (not specifically needed) 
        /// \note The image will become the color specified.
        ///
        wall(sf::Vector2f position, sf::Vector2f size, sf::Color object_color, std::string image_name = "");
        
        /// \brief Draw function for the wall.
        ///
        /// This function draw the wall to the render of the window. 
        /// 
        /// \param[in] window The window to render the image on
        ///
        void draw(sf::RenderWindow & window) override;
        
        /// \brief Function that gives de global bounds. 
        ///
        /// This function returns the globalbounds. The return value can be used
        /// in collision checking. 
        /// 
        /// \return The sf::floatrect of the wall object
        /// 
        sf::FloatRect getGlobalBounds() override;

        ///  \brief Funtion that returns object information. 
        ///
        /// This function returns object information. It does so in the following
        /// way: #drawable::object_information() + size + color + image_name
        /// 
        /// Example: WALL (2627.720947,2226.875000) (10.000000,10.000000) green grass.png
        ///
        /// \return The string with all the information in the way of the example
        ///
        std::string object_information() override;
    private:
        sf::Color object_color;
        sf::RectangleShape rectangle;
        std::string image_name;
        sf::Texture texture;
        
};

#endif //_WALL_HPP
