#include "drawable.hpp"


drawable::drawable(const sf::Vector2f & position, const sf::Vector2f & size, std::string type) :
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

bool drawable::within_range(float x, float y, float a, float b) {
    for (float i = x + 1; i<(y - 1); i += 4) {
        if (within(i, a, b)) {
            return true;
        }
    }
    return false;
}

void drawable::collapse(object_ptr object, collisions & the_collisions) {
    collision tmp(object);
    
    sf::Vector2f ob_position = object->position;
    sf::Vector2f ob_size = object->size;

    bool within_x = within_range(position.x, position.x + size.x, ob_position.x, (ob_position.x + ob_size.x));
    bool within_y = within_range(position.y, position.y + size.y, ob_position.y, (ob_position.y + ob_size.y));

    tmp.R = (within_y) && within(position.x + size.x, ob_position.x, ob_position.x + ob_size.x);
    tmp.L = (within_y) && within(position.x, ob_position.x, ob_position.x + ob_size.x);
    tmp.U = (within_x) && within(ob_position.y, position.y, position.y + size.y);
    tmp.D = (within_x) && within(ob_position.y + ob_size.y, position.y, position.y + size.y);

    if (tmp.R || tmp.U || tmp.L || tmp.D) {
        the_collisions.push_back(tmp);
    }
}

sf::Vector2f drawable::get_position() {
    return position;
}

sf::Vector2f drawable::get_size() {
    return size;
}

std::string drawable::object_information() {
    return type + " (" + std::to_string(position.x) + ',' + std::to_string(position.y) + ')';
}

std::string drawable::string_from_color(sf::Color & col) {
    const struct { sf::Color color; std::string name; } colors[]{
        {sf::Color::Yellow, "yellow" },
        {sf::Color::Red, "red" },
        {sf::Color::Blue, "blue" },
        {sf::Color::Black, "black" },
        {sf::Color::Cyan, "cyan" },
        {sf::Color::Green, "green" },
        {sf::Color::Magenta, "magenta" },
        {sf::Color::Transparent, "transparent" },
        {sf::Color::White, "white" },
        {sf::Color{165, 42, 42}, "brown" }
    };

    for (auto const & color : colors) {
        if (color.color == col) {
            return color.name;
        }
    }
    return "";
}

std::string drawable::get_type(){
    return type;
}

void drawable::set_type(std::string s){
    type = s;
}

void drawable::set_size(sf::Vector2f new_size){
    size = new_size;
}

void drawable::set_position(sf::Vector2f new_position) {
    position = new_position;
}

std::string drawable::get_image_name(){
    return "None";
};