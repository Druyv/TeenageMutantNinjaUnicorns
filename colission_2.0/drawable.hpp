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

class drawable;
class action;
struct collision;

typedef std::shared_ptr<drawable> object_ptr;
typedef std::vector<collision> collisions;
typedef std::vector<action> actions;
typedef std::vector<object_ptr> objects_vector;

struct collision {
    object_ptr the_object = nullptr;
    bool D = false;
    bool U = false;
    bool L = false;
    bool R = false;
    
    collision(object_ptr the_object):
        the_object(the_object)
    {}
    
    bool operator==(const collision & rhs){
        if (the_object == rhs.the_object && D==rhs.D && U==rhs.U && L==rhs.L && R==rhs.R){
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
/// It uses 2 std::function variables. One holds the condition
/// and the other the work. The condition has to return a bool and
/// should not have any paramters. The same goes for the work, except
/// for that the work function should not return anything.
///
/// Note that this was created by Wouter van Ooijen.
///
/// \date 19-1-2017
class action {
private:
        std::function< bool() > condition;
        std::function< void(object_ptr) > work;
public:
        /// \brief constructor 2 functions
        ///
        /// This constructor receives 2 std::functions and saves them as condition and work.
        ///
        /// \param[in] condition The condition under wicht to do the work
        /// \param[in] work The work to be done
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
        /// \sa sf::Keyboard::Key
        action(sf::Keyboard::Key key,std::function< void(object_ptr) > work) :
            condition( [key]()->bool { return sf::Keyboard::isKeyPressed(key); } ),
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
        /// \sa sf::Mouse::Button
        action(sf::Mouse::Button button, std::function< void(object_ptr) > work) :
            condition( [button]()->bool { return sf::Mouse::isButtonPressed(button); } ),
            work(work)
        {}

        /// \brief constructor char &, char and function
        ///
        /// This constructor receives 3 parameters. The first
        /// is a variable that has to be checked. This variable
        /// is received by reference because it is updated in the
        /// main. The second one is another character that has
        /// to be checked agains the first parameter. The third
        /// is a function as work. The constructor creates a lambda
        /// of the first and second parameter, capturing them by
        /// reference. That lambda returns a boolean if the character
        /// in check is equal to the character in c. 
        ///
        /// \param[in] check The first char that has to be compared with the second
        /// \param[in] c The second char that has to be compared with the first. 
        /// \param[in] work The work to be done
        /*action(char & check, char & c, std::function< void(object_ptr) > work)  :
            condition([&]()->bool{ return (check == c); }),
            work(work)
        {}*/

        /// \brief operator()
        ///
        /// This operator executes the function in condition and then
        /// checks the return value. If the condition returns true the
        /// work gets executed.
        void operator()(object_ptr object) {
            if (condition()) {
                work(object);
            }
        }
};

/*!
 * \class drawable
 *
 * \brief class that is inherited by all objects that are drawable
 *
 * class with a position, size and name, that is inherited by all 
 * object that can be drawn on the screen. 
 *
 * \date 18/01/17
 */
class drawable {
    protected:
	sf::Vector2f position;
	sf::Vector2f size;
	std::string type;
    public:
         bool going_left = false;//betere manier nodig
	/*! drawable(const sf::Vector2f & position, const sf::Vector2f & size, std::string name)
	* \brief constructor for a drawable
	*
	* constructor that initializes position, size and name of drawable
	*
	* \param[in] position		position of drawable, this is a sf::Vector2f and const
	* \param[in] size			size of drawable, this is a sf::Vector2f and const
	* \param[in] name			this is the name of the drawable and is an std::string
	*/
	drawable(const sf::Vector2f & position, const sf::Vector2f & size, std::string name);

	/*! virtual void draw(sf::RenderWindow & window)
	* \brief virtual draw function for a drawable
	*
	* virtual function that is defined in the subclasses of drawable
	*
	* \param[in] window			SFML window that is used to display the drawable 
	*/
	virtual void draw(sf::RenderWindow & window) = 0;

	/*! virtual void move(sf::RenderWindow & delta)
	* \brief move function for a drawable
	*
	* function that moves the drawable with a certian delta
	*
	* \param[in] delta			sf::Vector2f that determines with what verctor the drawable is moves
	*/
	virtual void move(sf::Vector2f delta);
	
	/*! virtual void jump(sf::Vector2f new_location);
	* \brief virtual draw function for a drawable
	*
	* virtual function that changes position of drawable to new location given
	*
	* \param[in] new_location	sf::Vector2f that is used as new position of drawable
	*/
	virtual void jump() {};
     
	/*! virtual sf::FloatRect getGlobalBounds();
	* \brief virtual getGlobalBounds function 
	*
	* virtual function that gives sf::Floatrect of perimeter from the drawable
	*
	*/
	virtual sf::FloatRect getGlobalBounds() = 0;
        
        /*!
	* \brief check and execute actions
	*
	* This function is used to call the operator() on all the actions
        * The run_actions function in this superclass is empty. This is for
        * the fact that some subclasses do not have actions.
	*
	*/
        virtual void run_actions(object_ptr object){};
        
        virtual bool within(float x, float a, float b);
        virtual bool within_range(float x, float y, float a, float b);
        virtual void collapse(object_ptr object, collisions & the_collisions);
        
        virtual sf::Vector2f get_position();
        virtual sf::Vector2f get_size();
        
        virtual  bool intersects(object_ptr other);
        
        virtual collision check_for_collisions(char c){collision tmp(nullptr); return tmp; };
        
        virtual std::string object_information();
        
        std::string string_from_color(sf::Color & col);
};

#endif // DRAWABLE_HPP
