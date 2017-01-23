#include <SFML/Graphics.hpp>
#include <memory>
#include <vector>

#include "unicorn.hpp"
#include "wall.hpp"
#include "factory.hpp"
#include <SFML/System/Vector2.hpp>

/*
 * check char action waarvoor gebruikt
 * mid air jumps checken
 * Bij op het up ding zetten de left en right van het zelfde object niet moeten zijn
 * die going left uit de superclass rucken
 */

int main(int argc, const char **argv){
    collisions the_collisions;
    
    // Create the main window
    sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "SFML window", sf::Style::Fullscreen);
    
    actions unicorn_actions = {
        action(sf::Keyboard::Left, [] (object_ptr object) {object->move(sf::Vector2f(-10.0,0.0));}),//check met < 0 of left -20
        action(sf::Keyboard::Right, [](object_ptr object) {object->move(sf::Vector2f(10.0,0.0));}),//object->going_left = false; 20
        action(sf::Keyboard::Space, [](object_ptr object) {object->jump();})
    };
    
    object_ptr the_unicorn;
    objects_vector objects;
    factory object_creation("/home/leo/Documents/colission_2.0/level1");
    
    try {
        the_unicorn = std::make_shared<unicorn>(sf::Vector2f(100, 100), "/home/leo/Documents/collision/tim_shizzle/v2.png", unicorn_actions, the_collisions);
        objects = object_creation.objects_from_file();
    } catch(const std::exception & e){
        std::cout << e.what();
        exit(0);
    }
    
    // Start the game loop
    while (window.isOpen()){
        the_collisions.clear();
        // Clear screen
        window.clear();
        
        for(const auto & object : objects){
            the_unicorn->collapse(object, the_collisions);
            object->draw(window);
        }
        
        the_unicorn->run_actions(the_unicorn);
        the_unicorn->draw(window);
        
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
    
    object_creation.write_information_to_file(objects, "level1");
    /*
     * WALL (0,700) (1380,70) red
     * WALL (300,600) (400,70) red
     * WALL (300,400) (300,20) red
     */
    
    return 0;
}

