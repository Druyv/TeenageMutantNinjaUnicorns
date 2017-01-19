///@file

#ifndef ACTION_HPP
#define ACTION_HPP

#include <functional>
#include <SFML/Graphics.hpp>

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
        std::function< void() > work;
public:
        /// \brief constructor 2 functions
        ///
        /// This constructor receives 2 std::functions and saves them as condition and work.
        ///
        /// \param[in] condition The condition under wicht to do the work
        /// \param[in] work The work to be done
        action(std::function< bool() > condition, std::function< void() > work) :
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
        action(sf::Keyboard::Key key,std::function< void() > work) :
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
        action(sf::Mouse::Button button, std::function< void() > work) :
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
        action(char & check, char c, std::function< void() > work)  :
            condition([&]()->bool{ return (check == c); }),
            work(work)
        {}

        /// \brief operator()
        ///
        /// This operator executes the function in condition and then
        /// checks the return value. If the condition returns true the
        /// work gets executed.
        void operator()() {
            if (condition()) {
                work();
            }
        }
};
#endif // ACTION_HPP
