#include <iostream>
#include <functional>
#include <SFML/Graphics.hpp>
#include "ball.hpp"
#include "wall.hpp"
#include "super.hpp"
class action {
private:
	std::function< bool() > condition;
	std::function< void() > work;
public:



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

int main( int argc, char *argv[] ){
	std::cout << "Starting application 01-05 array of actions\n";

	sf::RenderWindow window{ sf::VideoMode{ 1000, 500 }, "SFML window" };
	ball blokje{ sf::Vector2f{ 100.0, 100.0 },sf::Vector2f{10,10}};
    
    
	wall wall1{ sf::Vector2f{0.0 , 0.0},sf::Vector2f{10.0,500.0} };
	wall wall2{ sf::Vector2f{ 0.0 , 490.0 },sf::Vector2f{ 1000.0,10.0 } };
	wall wall3{ sf::Vector2f{ 0.0 , 0.0 },sf::Vector2f{ 1000.0,10.0 } };
	wall wall4{ sf::Vector2f{ 990.0 , 0.0 },sf::Vector2f{ 10.0,500.0 } };
	action actions[] = {
		action( sf::Keyboard::Left,  [&](){ blokje.jump( sf::Vector2f( -5.0,  0.0 )); }),
		action( sf::Keyboard::Right, [&](){ blokje.jump( sf::Vector2f( +5.0,  0.0 )); }),
		action( sf::Keyboard::Up,    [&](){ blokje.jump( sf::Vector2f(  0.0, -5.0 )); }),
		action( sf::Keyboard::Down,  [&](){ blokje.jump( sf::Vector2f(  0.0, +5.0 )); }),
        action([&](){return (blokje.collaps(wall4)=='R');},[&](){std::cerr<<"het is right";}),
        action([&](){return (blokje.collaps(wall3)=='D');},[&](){std::cerr<<"het is up";}),
        action([&](){return (blokje.collaps(wall2)=='U');},[&](){std::cerr<<"het is down";}),
        action([&](){return (blokje.collaps(wall1)=='L');},[&](){std::cerr<<"het is left";}),

        
        






	};

	while (window.isOpen()) {
		for( auto & action : actions ){
			action();
		}
		window.clear();
		blokje.draw( window );
		wall1.draw(window);
		wall2.draw(window);
		wall3.draw(window);
		wall4.draw(window);
		window.display();
		sf::sleep( sf::milliseconds( 20 ));
        sf::Event event;
	    while( window.pollEvent(event) ){
			if( event.type == sf::Event::Closed ){
				window.close();
			}
		}
	}

	std::cout << "Terminating application\n";
	return 0;
}

