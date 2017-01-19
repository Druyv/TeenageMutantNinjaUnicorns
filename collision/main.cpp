#include <iostream>
#include <functional>
#include <SFML/Graphics.hpp>
#include "ball.hpp"
#include "wall.hpp"
#include "super.hpp"
#include "action.hpp"
#include <vector>
int main( int argc, char *argv[] ){
	std::cout << "Starting application 01-05 array of actions\n";
char check = ' ';
	sf::RenderWindow window{ sf::VideoMode{ 1000, 500 }, "SFML window" };
	ball blokje;
    char gft = 'U';
    blokje  = ball{ sf::Vector2f{ 100.0, 100.0 },sf::Vector2f{10,10},
 {action(check,gft,[&](){blokje.jump( sf::Vector2f( 0.0, -10.0 ));})}};
    // check = ' ';
    
    std::vector<super *> muren={
        	new wall { sf::Vector2f{0.0 , 0.0},sf::Vector2f{10.0,500.0} },
            new wall { sf::Vector2f{ 0.0 , 490.0 },sf::Vector2f{ 1000.0,10.0 } },
            new wall { sf::Vector2f{ 500.0 , 100.0 },sf::Vector2f{ 500.0,10.0 } },
            new wall { sf::Vector2f{ 990.0 , 0.0 },sf::Vector2f{ 10.0,500.0 } }
            };
    
 
	std::vector<action> actions= {
		action( sf::Keyboard::Left,  [&](){ blokje.jump( sf::Vector2f( -1.0,  0.0 )); }),
		action( sf::Keyboard::Right, [&](){ blokje.jump( sf::Vector2f( +1.0,  0.0 )); }),
		action( sf::Keyboard::Up,    [&](){ blokje.jump( sf::Vector2f(  0.0, -1.0 )); }),  
		action( sf::Keyboard::Down,  [&](){ blokje.jump( sf::Vector2f(  0.0, +1.0 )); }),
    
        };

	while (window.isOpen()) {
        for( auto & action : actions ){
			action();
    }
		for( auto  act: muren ){
        check  = blokje.collaps(*act) ;
        blokje.run_actions();
		
		}
		window.clear();
		blokje.draw( window );
    for(auto & mu:muren){
        mu->draw(window);
    }
		window.display();
		sf::sleep( sf::milliseconds( 2 ));
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

