#include "unicorn.hpp"


unicorn::unicorn(sf::Vector2f position, std::string filename, actions & actions_array, collisions & the_collisions) :
	drawable{ position, sf::Vector2f{ 1.0,1.0 }, std::string{ "UNICORN" } },
	actions_array{ actions_array },
	unicorn_animation{animation{ position, filename }  },
	the_collisions{ the_collisions },
        spawn_location{position}
{
	size = unicorn_animation.get_size();
	unicorn_animation.setTextureRect(sf::IntRect(int(size.x), 0, -int(size.x), int(size.y)));
}

void unicorn::draw(sf::RenderWindow & window) {
	if (going_left) {
		if (!correctly_scaled) {
			//unicorn_animation.setTextureRect(sf::IntRect(0, 0, int(size.x), int(size.y)));
			correctly_scaled = true;
		}
	}
	else if (!going_left) {
		if (correctly_scaled) {
			//unicorn_animation.setTextureRect(sf::IntRect(int(size.x), 0, -int(size.x), int(size.y)));
			correctly_scaled = false;
		}
	}

	auto collision_u = check_for_collisions('U');
	auto collision_d = check_for_collisions('D');
        auto collision_r= check_for_collisions('R');
	auto collision_l = check_for_collisions('L');
        
        if (collision_r.R || collision_l.L ||collision_u.U ||collision_d.D ){
                   unicorn_animation.movement(9);
        }
        
        if(collision_u.U && collision_u.the_object->get_type() == "LOWER_BORDER"){
            std::cout << "You died\n";
            position = spawn_location;
            physics_object.set_gravity(3);
        }
        else{
            if (collision_d.D) {
                    jump_counter = 0;
            }
            if (jump_counter > 3) {
                    position.y -= physics_object.jumping(jump_counter);
                    unicorn_animation.movement(2);
                    jump_counter--;
                    physics_object.set_gravity(3);
            }
            else if (collision_u.U) {// && !(collision_u.L || collision_u.R || collision_u.D)
                    float pos_y = (collision_u.the_object->get_position().y) - size.y;
                    if (position.y != pos_y) {
                        position.y = pos_y;
                    }
                    physics_object.set_gravity(3);
            }
            else {// if (!collision_u.U)
                                    unicorn_animation.movement(9);

                    jump_counter = 0;
                    position.y += physics_object.falling();
            }
        }

	unicorn_animation.set_position(position);
	unicorn_animation.draw(window);
}

void unicorn::move(sf::Vector2f delta) {
	auto checker_R = check_for_collisions('R');
	auto checker_L = check_for_collisions('L');

	if (delta.x < 0 && !checker_L.L) {
		going_left = true;
                unicorn_animation.movement(1);
		position.x += delta.x;
		position.y += delta.y;
	}
	else if (delta.x >= 0 && !checker_R.R) {
		going_left = false;
                unicorn_animation.movement(0);
		position.x += delta.x;
		position.y += delta.y;
	}
}

void unicorn::run_actions(object_ptr object) {
	for (auto & actions : actions_array) {
		actions(object);
	}
}

void unicorn::jump() {
	auto checker = check_for_collisions('U');
	if (!jump_counter && checker.U) {
		jump_counter = 25;
	}
}

sf::FloatRect unicorn::getGlobalBounds() {
	return unicorn_animation.getGlobalBounds();
}

collision unicorn::check_for_collisions(char c) {
	for (const auto & one : the_collisions) {
		if (c == 'U' && one.U) {
			return one;
		}
		else if (c == 'D' && one.D) {
			return one;
		}
		else if (c == 'L' && one.L) {
			return one;
		}
		else if (c == 'R' && one.R) {
			return one;
		}
	}
	collision tmp(nullptr);
	return tmp;
}

//----------------------------------------------
//
//experimental
//
//----------------------------------------------

void unicorn::shoot(sf::Vector2f fire_position) {
	/*if (shoot_timeout == 100) {//>=100 veiliger of <= 100
	// Hier bullet object aanmaken en .fire doen met unicorn positie
	}
	if (shoot_timeout) {
	// Hier draw doen
	}*/
}

void unicorn::set_spawn_location(sf::Vector2f new_location){
   spawn_location = new_location; 
}