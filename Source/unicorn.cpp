#include "unicorn.hpp"
#include <iostream>
#include <SFML/Graphics/Rect.hpp>


unicorn::unicorn(sf::Vector2f position, std::string filename, actions & actions_array, collisions & the_collisions):
        drawable{position, sf::Vector2f{1.0,1.0}, std::string{"Unicorn"}},
        actions_array{actions_array},
        unicorn_animation{image_from_file{position, filename}},
        the_collisions{the_collisions}
{
            position = unicorn_animation.get_position();
            size = unicorn_animation.get_size();
            unicorn_animation.setTextureRect(sf::IntRect(size.x, 0, -size.x, size.y));
}
        
        /*
         * 		//unicorn_animation.scale(sf::Vector2f(-1.0f, 1.0f));
                //position = unicorn_animation.get_position();
                //std::cout << "going left " << position.x << ',' << position.y << '\n';
		//position.x+=size.x;//fout met draaien
                //size.x = -size.x;//toegevoegd
         */

void unicorn::draw(sf::RenderWindow & window) {
	if (going_left) {
            if (!correctly_scaled) {
                unicorn_animation.setTextureRect(sf::IntRect(0, 0, size.x, size.y));
                correctly_scaled = true;
		}
	}
	else if (!going_left) {
            if (correctly_scaled) {
                unicorn_animation.setTextureRect(sf::IntRect(size.x, 0, -size.x, size.y));
                correctly_scaled = false;
            }
	}
        
        auto collision_u = check_for_collisions('U');
        auto collision_d = check_for_collisions('D');
        
        if (collision_d.D){
            jump_counter = 0;
        }
        if( jump_counter > 1){
            position.y -= physics_object.jumping(jump_counter);
            jump_counter--;
            physics_object.set_gravity(0);
        }
        else if(collision_u.U){// && !(collision_u.L || collision_u.R || collision_u.D)
            float pos_y = (collision_u.the_object->get_position().y)-size.y;
            if(position.y != pos_y){
                position.y = pos_y;
            }
            physics_object.set_gravity(0);
        }
        else if(!collision_u.U){
            jump_counter = 0;
            position.y += physics_object.falling();
        }
        
        unicorn_animation.set_position(position);
        //unicorn_animation.set_size(size);//toegevoegd
	unicorn_animation.draw(window);
}

void unicorn::move(sf::Vector2f delta) {
        auto checker_R = check_for_collisions('R');
        auto checker_L = check_for_collisions('L');
        
        if(delta.x < 0 && !checker_L.L){
            going_left = true;
            position.x+=delta.x;
            position.y+=delta.y;
        }
        else if(delta.x >= 0 && !checker_R.R){
            going_left = false;
            position.x+=delta.x;
            position.y+=delta.y;
        }
}

void unicorn::run_actions(object_ptr object) {
	for (auto & actions : actions_array) {
		actions(object);
	}
}

void unicorn::jump(){
        auto checker = check_for_collisions('U');
        if(!jump_counter && checker.U){
            jump_counter = 25;
        }
}

sf::FloatRect unicorn::getGlobalBounds() {
	return unicorn_animation.getGlobalBounds();
}

collision unicorn::check_for_collisions(char c){
    for(const auto & one : the_collisions){
        if(c == 'U' && one.U){
            return one;
        }
        else if(c == 'D' && one.D){
            return one;
        }
        else if(c == 'L' && one.L){
            return one;
        }
        else if(c == 'R' && one.R){
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
    if (shoot_timeout == 100) {//>=100 veiliger of <= 100
	// Hier bullet object aanmaken en .fire doen met unicorn positie
    }
    if (shoot_timeout) {
	// Hier draw doen
    }
}