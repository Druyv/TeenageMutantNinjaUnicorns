#include <SFML/Graphics.hpp>
#include <memory>
#include <vector>

#include "unicorn.hpp"
#include "wall.hpp"
#include "factory.hpp"
#include "base_level.hpp"
#include "camera.hpp"
#include "background.hpp"
#include "soundtrack.hpp"
#include "npc.hpp"

int main(int argc, const char **argv) {
	collisions the_collisions;
	object_ptr dummy = nullptr;

	// Create the main window
	sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "The unicorn game", sf::Style::Fullscreen);

	actions unicorn_actions = {
		action(sf::Keyboard::Left, [](object_ptr object) {object->move(sf::Vector2f(-10.0,0.0)); }),
		action(sf::Keyboard::Right, [](object_ptr object) {object->move(sf::Vector2f(10.0,0.0)); }),
		action(sf::Keyboard::Space, [](object_ptr object) {object->jump(); })
	};

	std::shared_ptr<unicorn> the_unicorn;
	objects_vector objects;
	factory object_creation("level1");

	//Making mobs (should be in factory with next level
	std::vector<mob_ptr> all_mobs;
	all_mobs.push_back(std::make_shared<mob>(sf::Vector2f(2541.799316f, 1900.484375f), "mini_bunny.png"));


	try {
            objects = object_creation.objects_from_file();
            
            base_level base( object_creation.get_level_size() );
            base.push_back_borders(objects);
            
            the_unicorn = std::make_shared<unicorn>(object_creation.get_spawn(), "spreadsheet.png", unicorn_actions, the_collisions, all_mobs, objects);
		
	}
	catch (const std::exception & e) {
            std::cout << e.what();
            exit(0);
	}


	//Sound, camera, background
	background background_1("background2.png", object_creation.get_level_size());
	camera playercam(the_unicorn);
	soundtrack soundplayer("Soundtrack.wav");
	soundplayer.PlayMusic();

	// Start the game loop
	while (window.isOpen()) {
		the_collisions.clear();
		// Clear screen
		window.clear();
		background_1.draw(window);

		for (const auto & object : objects) {
			the_unicorn->collapse(object, the_collisions);
			object->draw(window);
		}
		for (auto objects : all_mobs) {
			//std::cout << "Drawing mobs" << std::endl;
			objects->draw(window);
			if (the_unicorn->getGlobalBounds().intersects(objects->getGlobalBounds())) {
				the_unicorn->damage();
			}
		}

		the_unicorn->run_actions(the_unicorn);
		the_unicorn->draw(window);

		playercam.follow(window);

		// Update the window
		window.display();


		// Process events
		sf::Event event;
		while (window.pollEvent(event)) {
			// Close window: exit
			if (event.type == sf::Event::Closed || event.key.code == sf::Keyboard::Escape) {
				window.close();
			}
		}
		sf::sleep(sf::milliseconds(20));
	}
	return 0;
}

