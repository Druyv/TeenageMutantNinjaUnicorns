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


int main(int argc, const char **argv) {
	collisions the_collisions;
	// Create the main window
	sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "The unicorn game", sf::Style::Fullscreen);

	actions unicorn_actions = {
		action(sf::Keyboard::A, [](object_ptr object) {object->move(sf::Vector2f(-10.0,0.0)); }),
		action(sf::Keyboard::D, [](object_ptr object) {object->move(sf::Vector2f(10.0,0.0)); }),
		action(sf::Keyboard::Space, [](object_ptr object) {object->jump(); }),
                action(sf::Keyboard::Left, [](object_ptr object) {object->move(sf::Vector2f(-10.0,0.0)); }),
		action(sf::Keyboard::Right, [](object_ptr object) {object->move(sf::Vector2f(10.0,0.0)); }),
	};

	//Menu and file management
	file_management manager_file("played_games/save_files_path.txt");
	menu_management manager_menu(window, manager_file);
	std::string level_path = manager_menu.start_game();
	std::cout << "Path for level" << level_path;


	std::shared_ptr<unicorn> the_unicorn;
    std::shared_ptr<image_from_file> end_point;
	objects_vector objects;
    objects_vector objects_tmp;
	std::shared_ptr<factory> object_creation = std::make_shared<factory>(level_path);
	std::vector<mob_ptr> all_mobs;


	try {
            objects_tmp = object_creation->objects_from_file();
            
            base_level base( object_creation->get_level_size() );
            base.push_back_borders(objects);
            
            the_unicorn = std::make_shared<unicorn>(object_creation->get_spawn(), "spreadsheet.png","rainbowspreadsheet.png", unicorn_actions, the_collisions, all_mobs, objects,manager_file.get_counter());
		
	}
	catch (const std::exception & e) {
            std::cout << e.what();
            exit(0);
	}
        
        
        for(const auto & object : objects_tmp){
            if (object->get_type() == "MOB"){
                all_mobs.push_back( std::make_shared<mob>(object->get_position(), "mini_bunny.png") );
            }
            else if(object->get_type() == "END"){
                end_point = std::make_shared<image_from_file>(object->get_position(), object->get_image_name() );
                end_point->set_type("END");
            }
            else{
                objects.push_back(object);
            }
        }

        //delete objects_tmp;
        
	//Sound, camera, background
	background background_1("background2.png", object_creation->get_level_size());
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
		for (auto object : all_mobs) {
			//std::cout << "Drawing mobs" << std::endl;
			object->draw(window);
			if (the_unicorn->getGlobalBounds().intersects(object->getGlobalBounds())) {
				the_unicorn->damage(object);
			}
		}
                
            end_point->draw(window);
            the_unicorn->run_actions(the_unicorn);
            the_unicorn->draw(window);

            playercam.follow(window);

            // Update the window
            window.display();
            
            if(the_unicorn->getGlobalBounds().intersects(end_point->getGlobalBounds() )){
                if (manager_file.get_counter() == 6){
                    std::cout << "You won!!\n";
                    auto won = image_from_file( sf::Vector2f{0,0}, "end.png" );
                    
                    won.set_scale(sf::VideoMode::getDesktopMode().width / 1920, 
                            sf::VideoMode::getDesktopMode().height / 1080);
                    std::cout << "Width: " << (float)(sf::VideoMode::getDesktopMode().width / 1920) << '\n';
                    std::cout << "Heigth: " << (float)(sf::VideoMode::getDesktopMode().height / 1080) << '\n';
                    
                    sf::Vector2f new_position {the_unicorn->get_position().x - (won.get_size().x/2),
                                                the_unicorn->get_position().y - (won.get_size().y/2)};
                    won.set_position(new_position);
                    
                    won.draw(window);
                    window.display();
                    sf::sleep(sf::milliseconds(3000));
                    exit(0);
                }
                try {
                    objects.clear();
                    objects_tmp.clear();
                    all_mobs.clear();
                    object_creation->change_input_to(manager_file.next_level());
                    objects_tmp = object_creation->objects_from_file();
                    base_level base( object_creation->get_level_size() );
                    base.push_back_borders(objects);
                    the_unicorn->set_spawn_location( object_creation->get_spawn() );
                }
                catch (const std::exception & e) {
                    std::cout << e.what();
                    exit(0);
                }

                for(const auto & object : objects_tmp){
                    if (object->get_type() == "MOB"){
                        all_mobs.push_back( std::make_shared<mob>(object->get_position(), "mini_bunny.png") );
                    }
                    else if(object->get_type() == "END"){
                        end_point = std::make_shared<image_from_file>(object->get_position(), object->get_image_name() );
                        end_point->set_type("END");
                    }
                    else{
                        objects.push_back(object);
                    }
                }
            }
            
            //pauze menu ding
            if( sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) ){
                manager_menu.display_pause_game();
            }

		// Process events
		sf::Event event;
		while (window.pollEvent(event)) {
			// Close window: exit
			if (event.type == sf::Event::Closed) {// || event.key.code == sf::Keyboard::Escape
				window.close();
			}
		}
		sf::sleep(sf::milliseconds(20));
	}
	return 0;
}

