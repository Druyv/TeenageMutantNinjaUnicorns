#include <SFML/Graphics.hpp>
#include "drawable.hpp"

int main(int argc, const char **argv){
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window", sf::Style::Fullscreen);

    // Start the game loop
    while (window.isOpen()){
        // Clear screen
        window.clear();
        
        /*
         Your code
        */
        
        // Update the window
        window.display();
        
        
        // Process events
        sf::Event event;
        while (window.pollEvent(event)){
            // Close window: exit
            if (event.type == sf::Event::Closed || event.key.code == sf::Keyboard::Escape) {
                window.close();
            }
        }
		sf::sleep(sf::milliseconds(20));
    }

    return 0;
}

