#include "base_level.hpp"

base_level::base_level(sf::Vector2f screen_size):
    screen_size{screen_size}
{   
    lower_wall = std::make_shared<wall>(sf::Vector2f{1000, screen_size.y}, sf::Vector2f{screen_size.x, 20}, sf::Color::Transparent);
    right_wall = std::make_shared<wall>(sf::Vector2f{screen_size.x+980, 420}, sf::Vector2f{20, screen_size.y-420}, sf::Color::Transparent);
    upper_wall = std::make_shared<wall>(sf::Vector2f{1000,400}, sf::Vector2f{screen_size.x, 20}, sf::Color::Transparent);
    left_wall = std::make_shared<wall>(sf::Vector2f{1000,420}, sf::Vector2f{20, screen_size.y-420}, sf::Color::Transparent);
    
    upper_wall->set_type("BORDER");
    left_wall->set_type("BORDER");
    lower_wall->set_type("LOWER_BORDER");
    right_wall->set_type("BORDER");
    
}

void base_level::push_back_borders(objects_vector & objects){
    objects.push_back( upper_wall );
    objects.push_back( left_wall );
    objects.push_back( lower_wall );
    objects.push_back( right_wall );
}
