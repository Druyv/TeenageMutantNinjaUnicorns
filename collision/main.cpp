#include <iostream>
#include <functional>
#include <SFML/Graphics.hpp>
#include "ball.hpp"
#include "wall.hpp"
#include "super.hpp"
//#include "action.hpp"
#include <vector>


#include <thread>
#include <chrono>
#include <mutex>
int main( int argc, char *argv[] ){
	std::cout << "Starting application 01-05 array of actions\n";
    char check = ' ';
	sf::RenderWindow window{ sf::VideoMode{ 1000, 500 }, "SFML window" };
    
    //ball blokje;
    
    char U = 'U';
    char D ='D';
    char L= 'L';
    char R ='R';
    
    
     ball blokje =ball{ sf::Vector2f{ 100.0, 100.0 },sf::Vector2f{10,10},
    {action(check,R,[](super & object){  object.jump( sf::Vector2f( -1.0, 0.0 ));}),
    action(check,L,[](super & object){  object.jump( sf::Vector2f( 1.0, 0.0 ));}),
    action(check,U,[](super & object){  object.jump( sf::Vector2f( 0.0, -1.0 ));}),
    action(check,D,[](super & object){ object.jump( sf::Vector2f( 0.0, 1.0 ));})}};
    // check = ' ';

    std::vector<wall> muren={
        	wall { sf::Vector2f{0.0 , 0.0},sf::Vector2f{10.0,500.0} },
            wall { sf::Vector2f{ 0.0 , 490.0 },sf::Vector2f{ 1000.0,10.0 } },
             wall { sf::Vector2f{ 500.0 , 100.0 },sf::Vector2f{ 500.0,10.0 } },
            wall { sf::Vector2f{ 990.0 , 0.0 },sf::Vector2f{ 10.0,500.0 } }
            };
    
 
	std::vector<action> actions= {
		action( sf::Keyboard::Left,  [](super & object){ object.jump( sf::Vector2f( -1.0,  0.0 )); }),
		action( sf::Keyboard::Right, [](super & object){ object.jump( sf::Vector2f( +1.0,  0.0 )); }),
		action( sf::Keyboard::Up,    [](super & object){ object.jump( sf::Vector2f(  0.0, -1.0 )); }),  
		action( sf::Keyboard::Down,  [](super & object){ object.jump( sf::Vector2f(  0.0, +1.0 )); }),
    
        };

	while (window.isOpen()) {
        for( auto & action : actions ){
			action(blokje);
    }
		for( auto  act: muren ){
        check  = blokje.collaps(act) ;
        blokje.run_actions(blokje);
		
		}
		window.clear();
		blokje.draw( window );
    for(auto & mu:muren){
        mu.draw(window);
    }
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

