///@file

#ifndef BASE_LEVEL_HPP
#define BASE_LEVEL_HPP

#include "wall.hpp"

/// \class base_level
///
/// \brief level border creation class
///
/// This class creates the level borders with the right sizes and positions
/// depending on the screen size given to the constructor. 
///
/// \date 26/01/17
///
class base_level {
    private:
        sf::Vector2f screen_size;
        object_ptr lower_wall;
        object_ptr right_wall;
        object_ptr upper_wall;
        object_ptr left_wall;
    public:
        /// \brief constructor screen size
	///
	/// This constructor receives the screen size and creates all the walls
        /// with the right sizes. It makes them transparent to make sure you can
        /// not see the screen borders. It also changes the type of the wall
        /// objects to make sure other objects can know that they are not regular
        /// wall objects but of a special type.
	///
	/// \param[in] screen_size The size of the screen
        ///
        base_level(sf::Vector2f screen_size);
        
        /// \brief Put walls in the walls vector
	///
	/// This function puts the level borders in the vector with all the wall
        /// objects. This makes sure they are drawn.
	///
	/// \param[in] objects The vector with al the other wall objects
        ///
        void push_back_borders(objects_vector & objects);
};

#endif //BASE_LEVEL_HPP
