#define _ITERATOR_DEBUG_LEVEL 0  

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
#include "menu.hpp"
#include "button.hpp"
#include "management.hpp"
#include "cutscene1.hpp"


int main(int argc, const char **argv) {
	collisions the_collisions;

	// Create the main window
	sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "The unicorn game", sf::Style::Fullscreen);

	// Load sound file
	soundtrack soundplayer("Soundtrack.wav");

	// Create unicorn actions
	actions unicorn_actions = {
		action(sf::Keyboard::A, [](object_ptr object) { object->move(sf::Vector2f(-10.0,0.0)); }),
		action(sf::Keyboard::D, [](object_ptr object) { object->move(sf::Vector2f(10.0,0.0)); }),
		action(sf::Keyboard::Space, [](object_ptr object) { object->jump(); }),
		action(sf::Keyboard::Up, [](object_ptr object) { object->jump(); }),
		action(sf::Keyboard::W, [](object_ptr object) { object->jump(); }),
		action(sf::Keyboard::Left, [](object_ptr object) { object->move(sf::Vector2f(-10.0,0.0)); }),
		action(sf::Keyboard::Right, [](object_ptr object) { object->move(sf::Vector2f(10.0,0.0)); }),
	};

	// Menu and file management
	file_management manager_file("played_games/save_files_path.txt", window, soundplayer);
	menu_management manager_menu(window, manager_file, soundplayer);
	std::string level_path = manager_menu.start_game();
	std::cout << "Path for level" << level_path;


	// Create the different pointers to the objects
	std::shared_ptr<unicorn> the_unicorn;
	std::shared_ptr<image_from_file> end_point;
	objects_vector objects;
	objects_vector objects_tmp;
	std::shared_ptr<factory> object_creation = std::make_shared<factory>(level_path);
	std::vector<mob_ptr> all_mobs;


	///Read objects from file
	try {
		objects_tmp = object_creation->objects_from_file();
		base_level base(object_creation->get_level_size());
		base.push_back_borders(objects);
		the_unicorn = std::make_shared<unicorn>(
			object_creation->get_spawn(),
			"spreadsheet.png",
			"rainbowspreadsheet.png",
			unicorn_actions,
			the_collisions,
			all_mobs,
			objects, manager_file.get_counter(),
			soundplayer
			);
	}
	catch (const std::exception & e) {
		std::cout << e.what();
		exit(0);
	}

	// Fill the different types of objects with their objects
	for (const auto & object : objects_tmp) {
		if (object->get_type() == "MOB") {
			all_mobs.push_back(std::make_shared<mob>(object->get_position(), "mini_bunny.png"));
		}
		else if (object->get_type() == "END") {
			end_point = std::make_shared<image_from_file>(object->get_position(), object->get_image_name());
			end_point->set_type("END");
		}
		else {
			objects.push_back(object);
		}
	}

	// Set up the background and playercam
	background background_1("background2.png", object_creation->get_level_size());
	camera playercam(the_unicorn);

	// Start the sound
	soundplayer.playmusic();

	// Start the game loop
	while (window.isOpen()) {
		//  Clear the collisions vector
		the_collisions.clear();

		// Clear screen
		window.clear();

		// Draw the background
		background_1.draw(window);

		// Check wall collisions and draw the walls
		for (const auto & object : objects) {
			the_unicorn->collapse(object, the_collisions);
			object->draw(window);
		}

		// Check collisions with the mobs and draw them
		for (auto object : all_mobs) {
			object->draw(window);
			if (the_unicorn->getGlobalBounds().intersects(object->getGlobalBounds())) {
				the_unicorn->damage(object);
			}
		}

		// Draw the end point and the unicorn and run the actions of the unicorn
		end_point->draw(window);
		the_unicorn->run_actions(the_unicorn);
		the_unicorn->draw(window);

		// Tell the playercam to start following the object
		playercam.follow(window);

		// Update the window
		window.display();

		// Check if the unicorn hits the end point
		if (the_unicorn->getGlobalBounds().intersects(end_point->getGlobalBounds())) {
			// Display the you won text
			if (manager_file.get_counter() == 6) {
				auto won = image_from_file(sf::Vector2f{ 0,0 }, "end.png");
				won.set_scale(0.65f, 0.65f);
				sf::Vector2f new_position{
					the_unicorn->get_position().x - (won.get_size().x / 2),
					the_unicorn->get_position().y - (won.get_size().y / 2)
				};
				won.set_position(new_position);
				won.draw(window);
				window.display();
				while (1) {
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
						break;
					}
				}
				exit(0);
			}
			// Play a cut scene
			else  if (manager_file.get_counter() == 3) {
				sf::View playerCam(sf::FloatRect(0, 0, float(window.getSize().x), float(window.getSize().y)));
				playerCam.setCenter(sf::Vector2f{ (float)window.getSize().x / 2, (float)window.getSize().y / 2 });
				window.setView(playerCam);
				cutscene1 scene1(window, soundplayer);
				scene1.cyan_island();
			}

			// Load a new level
			try {
				objects.clear();
				objects_tmp.clear();
				all_mobs.clear();
				object_creation->change_input_to(manager_file.next_level());
				objects_tmp = object_creation->objects_from_file();
				base_level base(object_creation->get_level_size());
				base.push_back_borders(objects);
				the_unicorn->set_spawn_location(object_creation->get_spawn());
			}
			catch (const std::exception & e) {
				std::cout << e.what();
				exit(0);
			}
			for (const auto & object : objects_tmp) {
				if (object->get_type() == "MOB") {
					all_mobs.push_back(std::make_shared<mob>(object->get_position(), "mini_bunny.png"));
				}
				else if (object->get_type() == "END") {
					end_point = std::make_shared<image_from_file>(object->get_position(), object->get_image_name());
					end_point->set_type("END");
				}
				else {
					objects.push_back(object);
				}
			}
		}

		// Open the pause menu
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
			manager_menu.display_pause_game();
		}

		// Process events
		sf::Event event;
		while (window.pollEvent(event)) {
			// Close window: exit
			if (event.type == sf::Event::Closed) {
				window.close();
			}
            else{ break; }
            
		}

		// Game loop delay
		sf::sleep(sf::milliseconds(20));
	}
	return 0;
}