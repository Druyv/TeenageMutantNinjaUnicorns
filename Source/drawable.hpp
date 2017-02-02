///@file

#ifndef DRAWABLE_HPP
#define DRAWABLE_HPP

#include <SFML/Graphics.hpp>
#include <exception>
#include <string>
#include <iostream>
#include <vector>
#include <functional>
#include <memory>

#include "physics.hpp"
#include "typedefs.hpp"


/// \struct collision
///
/// \brief a collision
///
/// This struct can be used to find out what side
/// a collision happened.
///
struct collision {
    object_ptr the_object = nullptr;
    bool D = false;
    bool U = false;
    bool L = false;
    bool R = false;
    
    /// \brief constructor object ptr
    ///
    /// \param[in] the_object The object we have a collision with
    ///
    collision(object_ptr the_object):
        the_object(the_object)
    {}
    
    /// \brief operator==
    /// 
    /// This operator is for checking if every element of a collision
    /// is the same as another collision.
    ///
    /// \param rhs collision& The other object for the check
    /// \return bool Returns if the objects variables are the same
    ///
    bool operator==(const collision & rhs) {
        if (the_object == rhs.the_object && D == rhs.D && U == rhs.U && L == rhs.L && R == rhs.R) {
            return true;
        }
        return false;
    }
};

/// \class action
///
/// \brief actions that a charater can do
///
/// This class can be used to create actions for ingame characters.
/// It uses 2 <a href="http://en.cppreference.com/w/cpp/utility/functional/function ">std::function</a>
/// variables. One holds the condition
/// and the other the work. The condition has to return a bool and
/// should not have any paramters. The same goes for the work, except
/// for that the work function should not return anything.
///
/// \note that this was created by Wouter van Ooijen.
///
class action {
    private:
        std::function< bool() > condition;
	std::function< void(object_ptr) > work;
        std::function< void() > work_no_ptr;
    public:
	/// \brief constructor 2 functions
	///
	/// This constructor receives 2 std::functions and saves them as condition and work.
	///
	/// \param[in] condition The condition under wicht to do the work
	/// \param[in] work The work to be done
        ///
	action(std::function< bool() > condition, std::function< void(object_ptr) > work) :
		condition(condition),
		work(work)
	{}

	/// \brief constructor key and function
	///
	/// This constructor receives a sfml key and creates a lambda.
	/// That lambda returns true when the key is pressed. It also
	/// needs a function as work to be done. 
	///
	/// \param[in] key The key to check
	/// \param[in] work The work to be done
	/// \sa <a href="https://www.sfml-dev.org/documentation/2.0/classsf_1_1Keyboard.php">key</a>
        /// 
	action(sf::Keyboard::Key key, std::function< void(object_ptr) > work) :
		condition([key]()->bool { return sf::Keyboard::isKeyPressed(key); }),
		work(work)
	{}

	/// \brief constructor moust button and function
	///
	/// This constructor receives a sfml mouse button and creates a lambda.
	/// That lambda returns true when the mous button is pressed. It also
	/// needs a function as work to be done. 
	///
	/// \param[in] button The mouse button to check
	/// \param[in] work The work to be done
	/// \sa <a href="https://www.sfml-dev.org/documentation/2.0/classsf_1_1Mouse.php">button</a>
        ///
	action(sf::Mouse::Button button, std::function< void(object_ptr) > work) :
		condition([button]()->bool { return sf::Mouse::isButtonPressed(button); }),
		work(work)
	{}   
                
        /// \brief constructor button and function
	///
	/// This constructor receives 2 parameters. The first
	/// is a variable that has to be checked. The second
	/// is a function as work. The constructor creates a lambda
	/// of the first parameter, capturing it by
	/// reference. That lambda returns a boolean if the button is
        /// pressed
	///
	/// \param[in] condition The condition under wich to do the work
	/// \param[in] work The work to be done
        action(sf::Mouse::Button button, std::function< void() > work) :
		condition([button]()->bool { return sf::Mouse::isButtonPressed(button); }),
		work_no_ptr(work)
	{}

	/// \brief operator()
	///
	/// This operator executes the function in condition and then
	/// checks the return value. If the condition returns true the
	/// work gets executed.
        ///
	void operator()(object_ptr object) {
		if (condition()) {
			work(object);
		}
	}
        
        /// \brief operator()
	///
	/// This operator executes the function in condition and then
	/// checks the return value. If the condition returns true the
	/// work gets executed.
        ///
        void operator()(){
            if(condition()){
                work_no_ptr();
            }
        }
};

/// \class drawable
///
/// \brief class that is inherited by all objects that are drawable
///
/// class with a position, size and type, that is inherited by all
/// object that can be drawn on the screen.
///
class drawable {
protected:
	sf::Vector2f position;
	sf::Vector2f size;
	std::string type;
public:

	/// \brief constructor for a drawable
	///
	/// constructor that initializes position, size and name of drawable
	///
	/// \param[in] position Position of drawable, this is a sf::Vector2f and const
	/// \param[in] size Tize of drawable, this is a sf::Vector2f and const
	/// \param[in] name This is the name of the drawable and is an std::string
        ///
	drawable(const sf::Vector2f & position, const sf::Vector2f & size, std::string name);


	/// \brief virtual draw function for a drawable
	///
	/// virtual function that is defined in the subclasses of drawable
	///
	/// \param[in] window SFML window that is used to display the drawable
        ///
	virtual void draw(sf::RenderWindow & window) = 0;

	/// \brief Move function for a drawable
	///
	/// Function that moves the drawable with a certian delta
	///
	/// \param[in] delta The delta with wich to move the object.
        ///
	virtual void move(sf::Vector2f delta);

	/// \brief virtual draw function for a drawable
	///
	/// Virtual function that changes position of drawable to new location given
        ///
	virtual void jump() {};

	/// \brief virtual getGlobalBounds function
	///
	/// virtual function that gives #sf::Floatrect of perimeter from the drawable
        ///
	virtual sf::FloatRect getGlobalBounds() = 0;

	/// \brief check and execute actions
	///
	/// This function is used to call the operator() on all the actions
	/// The run_actions function in this superclass is empty. This is for
	/// the fact that some subclasses do not have actions.
        /// 
        /// \param[in] object The object to use in certain actions
	/// \return sf::FloatRect with the globalbounds
        ///
	virtual void run_actions(object_ptr object) {};

	/// \brief check x between a and b
	///
	/// This function checks if the x parameter is between
	/// the a and b parameters.
	///
	/// \param[in] x The x variable for the check
	/// \param[in] a The a variable for the check
	/// \param[in] b The b variable for the check
	///
	/// \return Returns if x is between a and b
        ///
	virtual bool within(float x, float a, float b);

	/// \brief check all pixels between x and y
	///
	/// This function checks if any pixel between x and y
	/// is between a and b.
	///
	/// \param[in] x float The x value of the range of pixels to check
	/// \param[in] y float The y value of the range of pixels to check
	/// \param[in] a float The first value used for checking (a>=pixel)
	/// \param[in] b float The second value used for checking (b<=pixel)
	///
	/// \return Returns if all pixels between x and y are between a and b
        ///
	virtual bool within_range(float x, float y, float a, float b);

	/// \brief check for collision with object
	///
	/// This function checks if this object is colliding with another
	/// object. The output is put into a vector of collisions.
	///
	/// \param[in] object The other object for the collision check
	/// \param[out] the_collisions The vector to put the collision in
        ///
	virtual void collapse(object_ptr object, collisions & the_collisions);

	/// \brief Get the position
	///
	/// This function returns the position of the object.
        ///
	virtual sf::Vector2f get_position();

	/// \brief get size
	/// 
	/// This function returns the size of the object.
	/// 
	/// \return The size of the object
        ///
	virtual sf::Vector2f get_size();

	/// \brief check for collisions
	///
	/// This function returns a collision struct type that is empty.
	/// The function needs to be fully implemented in subclasses if they
	/// need it.
	///
	/// \param[in] c The collision side that needs to be checked
        ///
	virtual collision check_for_collisions(char c) { collision tmp(nullptr); return tmp; };

	///
	/// \brief object information as string
	///
	/// This function returns al the object information.
	/// The information is returned as a string an contains
	/// the type and the position.
	///
	/// output example: WALL (0.000000,700.000000)
	/// \return The object information
        ///
	virtual std::string object_information();

	/// \brief object information as string
	///
	/// This function returns the color of an object.
	/// It requires a color as parameter and converts
	/// this to a string.
	///
	/// \param[in] col The color that needs to be converted
	/// \return The color as a string
        ///
	virtual std::string string_from_color(sf::Color & col);
        
        /// \brief Get the type
	///
	/// This function returns the type of the object.
	///
	/// \return The type of the object
        ///
        std::string get_type();
        
        /// \brief Set the type
	///
	/// This function sets the type of the object to a new type.
	///
	/// \param[in] s The new type for the object
        ///
        void set_type(std::string s);
        
        /// \brief Set the size
	///
	/// This function sets the size of an object to a new size.
	///
	/// \param[in] new_size The new size for the object
        void set_size(sf::Vector2f new_size);
        
        /// \brief Set the position
	///
	/// This function sets the position of an object to a new position.
	///
	/// \param[in] new_position The new position for the object
        ///
        void set_position(sf::Vector2f new_position);
        
	/// \brief get image name
	/// 
	/// getter for the  name of the image used .
	///
	/// 
	virtual std::string get_image_name();
};
#endif //DRAWABLE_HPP
