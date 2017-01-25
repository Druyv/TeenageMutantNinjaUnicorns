#ifndef PHYSICS_HPP
#define PHYSICS_HPP
 ///
 /// \class physics
 ///
 /// \brief class with physics function 
 ///
 ///  This class containing all forces needed in the game.
 ///
 /// \date 23/01/17
 ///
class physics {
public:
	 ///
	 /// \funtion void  set_gravity(int value)
	 ///
	 /// \brief set function for the gravity counter. 
	 ///
	 ///  setter for the gravity counter
	 /// \param[in] value int where the gravity_counter will be set on 

	 ///
        void set_gravity (int value);
 	 ///
	 /// \funtion int get_gravity()
	 ///
	 /// \brief get function for the gravity_counter. 
	 ///
	 ///  getter for the grafity counter
	 ///

	 ///
        int get_gravity();
	 ///
	 /// \funtion float falling()
	 ///
	 /// \brief the working function that contains the gavity. 
	 ///
	 ///  function that makes falling in the game look natural
	 ///

	 ///
        float falling();
	 ///
	 /// \funtion float jumping(int counter)
	 ///
	 /// \brief the working function for jumping. 
	 ///
	 ///  function that makes jumping in the game possible and look natural 
	 ///
	 /// \param[in] counter The counter for the jump
        float jumping(int counter);
private:
        int gravity_counter = 3;
};

#endif // PHYSICS_HPP

