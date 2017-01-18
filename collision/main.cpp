#include <iostream>
#include <functional>
#include <SFML/Graphics.hpp>


#include "ball.hpp"
#include "wall.hpp"
#include "rectangle.hpp"
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
	ball my_ball{ sf::Vector2f{ 100.0, 100.0 },sf::Vector2f{+1.0,+1.0} ,10.0 };
	wall my_wall1{ sf::Vector2f{0.0 , 0.0},sf::Vector2f{10.0,500.0} };
	wall my_wall2{ sf::Vector2f{ 0.0 , 490.0 },sf::Vector2f{ 1000.0,10.0 } };
	wall my_wall3{ sf::Vector2f{ 0.0 , 0.0 },sf::Vector2f{ 1000.0,10.0 } };
	wall my_wall4{ sf::Vector2f{ 990.0 , 0.0 },sf::Vector2f{ 10.0,500.0 } };
	rectangle blokje{ sf::Vector2f{30.0,30.0}, sf::Vector2f{40.0,40.0} };
	action actions[] = {
		action( sf::Keyboard::Left,  [&](){ blokje.move( sf::Vector2f( -5.0,  0.0 )); }),
		action( sf::Keyboard::Right, [&](){ blokje.move( sf::Vector2f( +5.0,  0.0 )); }),
		action( sf::Keyboard::Up,    [&](){ blokje.move( sf::Vector2f(  0.0, -5.0 )); }),
		action( sf::Keyboard::Down,  [&](){ blokje.move( sf::Vector2f(  0.0, +5.0 )); }),
		action( sf::Mouse::Left,     [&](){ blokje.jump( sf::Mouse::getPosition( window )); }),
		action([]() {return true; },[&]() {my_ball.automove(); }),
		action([&]() {return my_ball.collaps2(my_wall1.getposition(),my_wall1.getsize()); }, [&]() { }),
		action([&]() {return my_ball.collaps2(my_wall2.getposition(),my_wall2.getsize()); }, [&]() { }),
		action([&]() {return my_ball.collaps2(my_wall3.getposition(),my_wall3.getsize()); }, [&]() { }),
		action([&]() {return my_ball.collaps2(my_wall4.getposition(),my_wall4.getsize()); }, [&]() { }),
		action([&]() {return my_ball.collaps2(blokje.getposition(),blokje.getsize()); }, [&](){})







	};

	while (window.isOpen()) {
		std::cout<<"running";
		for( auto & action : actions ){
			action();
		}
		window.clear();
		my_ball.draw( window );
		my_wall1.draw(window);
		my_wall2.draw(window);
		my_wall3.draw(window);
		my_wall4.draw(window);
		blokje.draw(window);
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

