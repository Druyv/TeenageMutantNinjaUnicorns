#include "unicorn.hpp"


unicorn::unicorn(sf::Vector2f position, std::string filename,std::string file_rainbow, actions & actions_array, collisions & the_collisions, std::vector<mob_ptr> & all_mobs, objects_vector & objects) :
	drawable{ position, sf::Vector2f{ 1.0,1.0 }, std::string{ "UNICORN" } },
	actions_array{ actions_array },
	unicorn_animation{animation{ position, filename,7.0,5.0 }  },
	rainbow{animation{position,file_rainbow,8.0,1.0}},
	the_collisions{ the_collisions },
        spawn_location{position},
	all_mobs{all_mobs},
	//objects{objects},
	weapon(position, "Nyan-Cat.png", all_mobs, objects)
{
        if (!font.loadFromFile("Pixeled.ttf")){
            throw font_load_error("Pixeled.ttf");
        }
        text.setFont(font);
        text.setCharacterSize(24);
        text.setFillColor(sf::Color::Red);
        
	size = unicorn_animation.get_size();
	unicorn_animation.setTextureRect(sf::IntRect(int(size.x), 0, -int(size.x), int(size.y)));
	actions_array.push_back(action(sf::Keyboard::LControl, [&](object_ptr object) {if (!shoot_timeout) { shoot_timeout = 50; } }));
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
        if(mob_touch_counter){
            position.x += mob_touch_counter;
            position.y -= 5;
            if(mob_touch_counter < 0){
                mob_touch_counter++;
            }
            else{
                mob_touch_counter--;
            }
            physics_object.set_gravity(3);
        }

	auto collision_u = check_for_collisions('U');
	auto collision_d = check_for_collisions('D');
        auto collision_r= check_for_collisions('R');
	auto collision_l = check_for_collisions('L');
        
        if (collision_r.R || collision_l.L ||collision_u.U ||collision_d.D ){
                   unicorn_animation.movement(9);
        }
        
        if((collision_u.U && collision_u.the_object->get_type() == "LOWER_BORDER") || lives <= 0){
            std::cout << "You died\n";
            position = spawn_location;
            for (auto & mob : all_mobs) {
                mob->revive();
            }
            weapon.set_position(spawn_location);
            shoot_timeout = 0;
            lives = 3;
            mob_touch_counter = 0;
            physics_object.set_gravity(3);
            
            jump_counter = 0;
            text.setString("You died!!");
            text.setPosition(spawn_location.x+100, spawn_location.y+100);
            text_counter = 70;
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
            else if (collision_u.U && !got_hit) {// && !(collision_u.L || collision_u.R || collision_u.D)
                    float pos_y = (collision_u.the_object->get_position().y) - size.y;
                    if (position.y != pos_y) {
                        position.y = pos_y;
                    }
                    physics_object.set_gravity(3);
            }
            else if(!mob_touch_counter){
                unicorn_animation.movement(9);
                jump_counter = 0;
                position.y += physics_object.falling();
            }
            
            if (going_left) {
		shoot(unicorn_animation.get_position(), window, sf::Vector2f(-10.0, 0.0));
            }
            else {
		shoot(unicorn_animation.get_position(), window, sf::Vector2f(10.0, 0.0));
            }
        }
        
        if(text_counter){
            window.draw(text);
            text_counter--;
        }
        
        got_hit = false;
	rainbow.set_position((position - sf::Vector2f(window.getSize().x / 2.0 - size.x / 2.0, window.getSize().y / 2.0)));
	rainbow.draw(window);
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

void unicorn::shoot(sf::Vector2f fire_position, sf::RenderWindow & window, sf::Vector2f offset) {
	if (shoot_timeout >= 50) {
		weapon.shoot(window, shoot_timeout, offset, fire_position);
		std::cout << "Shoot unicorn" <<all_mobs[0]->get_live() << std::endl;
		//all_mobs[0]->die();
	}
	if (shoot_timeout) {
		shoot_timeout--;
		weapon.shoot(window, shoot_timeout);
	}
}

void unicorn::set_spawn_location(sf::Vector2f new_location){
   spawn_location = new_location;
   position = new_location;
   unicorn_animation.set_position(new_location);
}


//----------------------------------------------
//
//experimental
//
//----------------------------------------------
void unicorn::damage(mob_ptr other) {
	lives--;
        auto other_pos = other->get_position();
        if(position.x < other_pos.x){
            mob_touch_counter = -20;
        }
        else{
            mob_touch_counter = 20;
        }
        got_hit = true;
	std::cout << "Lives: " << lives << std::endl;
}
