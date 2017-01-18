#include <SFML/Graphics.hpp>
#include "drawable.hpp"

int main(int argc, const char **argv){
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");

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
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
    }

    return 0;
}

