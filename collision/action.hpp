
#ifndef _ACTION_HPP
#define _ACTION_HPP

#include <iostream>
#include <vector>
#include <functional>
class action {
private:
	std::function< bool() > condition;
	std::function< void() > work;
public:

  
	action( char & check, char c, std::function< void() > work ) :
		condition( [& ] () -> bool {
            return  check == c;}
		),
    work(work)
    {}

	action(
	   std::function< bool() > condition,
	   std::function< void() > work
	) : condition( condition ),
		work( work )
	{}

	action(
		sf::Keyboard::Key key,
		std::function< void() > work
	) :
		condition(
			[ key ]()->bool { return sf::Keyboard::isKeyPressed( key ); }
		),
		work(work)
	{}

	action(
		sf::Mouse::Button button,
		std::function< void() > work
	) :
		condition(
			[ button ]()->bool { return sf::Mouse::isButtonPressed( button ); }
		),
		work(work)
	{}


	void operator()(){
		if( condition() ){
			work();
		}
	}
};

#endif