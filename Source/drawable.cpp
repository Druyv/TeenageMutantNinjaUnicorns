#include "drawable.hpp"

drawable::drawable(const sf::Vector2f & position, const sf::Vector2f & size, std::string type):
	position{position},
	size{size},
	type{type}
{}

void drawable::move(sf::Vector2f delta) {
	position += delta;
}

bool drawable::within(float x, float a, float b) {
	return (x >= a) && (x <= b);
}
    
bool drawable::within_range(float x, float y,float a, float b){
        for (float i  = x+1; i<y; i++){
            if (within(i,a,b)){
                return true;
            }
        }
        return false;
}

void drawable::collapse(object_ptr object, collisions & the_collisions){
        collision tmp(object);
        sf::Vector2f ob_position = object->position;
        sf::Vector2f ob_size = object->size;
        
        bool within_x = within_range( position.x, position.x+size.x, ob_position.x, (ob_position.x+ob_size.x) );
        bool within_y = within_range( position.y, position.y+size.y, ob_position.y, (ob_position.y+ob_size.y) );
        
        tmp.R = (within_y) and within( position.x+size.x, ob_position.x, ob_position.x + ob_size.x);
        tmp.L = (within_y) and within( position.x, ob_position.x, ob_position.x + ob_size.x);
        tmp.U = (within_x) and within( ob_position.y, position.y, position.y+size.y);
        tmp.D = (within_x) and within( ob_position.y+ob_size.y, position.y, position.y+size.y);
        
        //if (tmp.R || tmp.u || tmp.L || tmp.D){ push back }
        the_collisions.push_back(tmp);
}

sf::Vector2f drawable::get_position(){
    return position;
}

sf::Vector2f drawable::get_size(){
    return size;
}

std::string drawable::object_information(){
    return type + " (" + std::to_string(position.x) + ',' + std::to_string(position.y) + ')';
}

std::string drawable::string_from_color(sf::Color & col){
    const struct { sf::Color color; std::string name; } colors[]{
        	{sf::Color::Yellow, "yellow" },
		{sf::Color::Red, "red" },
		{sf::Color::Blue, "blue" },
		{sf::Color::Black, "black" },
		{sf::Color::Cyan, "cyan" },
		{sf::Color::Green, "green" },
		{sf::Color::Magenta, "magenta" },
		{sf::Color::Transparent, "transparant" }
    };

    for (auto const & color : colors) {
        if (color.color == col) {
            return color.name;
        }
    }
    
    return "";
}