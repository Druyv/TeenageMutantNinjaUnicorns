///@file

#ifndef PHYSICS_HPP
#define PHYSICS_HPP


/// \class physics
///
/// \brief Class with physics function 
///
/// This class containing all forces needed in the game.
///
/// \date 23/01/17
///
class physics {
public:
        /// \brief Set function for the gravity counter. 
	///
	/// Setter for the gravity counter
        ///
	/// \param[in] value int where the gravity_counter will be set on 
        ///
        void set_gravity (int value);

        /// \brief Get function for the gravity_counter. 
	///
	/// Getter for the grafity counter
        ///
        int get_gravity();

	 /// \brief the working function that contains the gavity. 
	 ///
	 /// Function that makes falling in the game look natural
	 ///
        float falling();

	/// \brief The working function for jumping. 
	///
	/// Function that makes jumping in the game possible and look natural 
	///
	/// \param[in] counter The counter for the jump
        ///
        float jumping(int counter);
private:
        int gravity_counter = 3;
};

#endif // PHYSICS_HPP

