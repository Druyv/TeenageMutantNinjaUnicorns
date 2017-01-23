#include "physics.hpp"

void physics::set_gravity (int value){
        gravity_counter = value;
}

int physics::get_gravity(){
        return gravity_counter;
}

float physics::falling(){
        gravity_counter++;
        return gravity_counter*gravity_counter/(36.8+1/3/10);
}

float physics::jumping(int counter){
        return counter*counter/(36.8+1/3/10);
}