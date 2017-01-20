
#ifndef _ACTION_HPP
#define _ACTION_HPP

#include <iostream>
#include <vector>
#include <functional>
class action {
private:
	std::function< bool() > condition;
	std::function< void(super) > work;
public:

  
	action( char & check, char c, std::function< void(super ) > work ) :
		condition( [& ] () -> bool {
            return  check == c;}
		),
    work(work)
    {}

	action(
	   std::function< bool() > condition,
	   std::function< void(super) > work
	) : condition( condition ),
		work( work )
	{}

	action(
		sf::Keyboard::Key key,
		std::function< void(super) > work
	) :
		condition(
			[ key ]()->bool { return sf::Keyboard::isKeyPressed( key ); }
		),
		work(work)
	{}

	action(
		sf::Mouse::Button button,
		std::function< void(super) > work
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
    	void operator()(super & object){
		if( condition() ){
			work(object);
		}
	}
};

#endif