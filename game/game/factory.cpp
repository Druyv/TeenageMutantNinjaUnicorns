#include "factory.hpp"



factory::factory(std::string filename)
{
    change_input_to(filename);
}

void factory::change_input_to(std::string new_filename){
    if( input.is_open() ){
        input.close();
    }
    input.open (new_filename);
}

object_ptr factory::read_line(){
    std::string type;
    sf::Vector2f position;
    input >> type;
    input >> position;
    
    if (type == "WALL"){
       sf::Vector2f size;
       sf::Color object_color;
       std::string image_name;
       input >> size >> object_color >> image_name;
       std::cout << image_name << '\n';
       return object_ptr( new wall(position, size, object_color, image_name) );
    }
    else if (type == "SPAWN"){
        spawn = position;
        throw (const std::string)"SPAWN";
    }
    else if (type == "LEVEL_SIZE"){
        level_size = position;
        throw (const std::string)"LEVEL_SIZE";
    }
    else if (type == "MOB"){
        std::string image_name;
        input >> image_name;
        return object_ptr( new mob(position, image_name) );
    }
    throw unknown_type(type);
}

objects_vector factory::objects_from_file(){
    file_line_counter = 1;
    objects_vector level;
    while(1){
        try {
            level.push_back( read_line() );
        }
        catch(const end_of_file & eof){
            std::cout << eof.what() << '\n';
            return level;
        }
        catch(const std::string s){
            std::cout << "Caught the " << s << '\n';
            file_line_counter++;
            continue;
        }
        catch(const std::exception & e){
            std::cout << e.what() << "\nIn file at line: " << file_line_counter << '\n';
            exit(0);
        }
        file_line_counter++;
    }
    
    return level;
}

void factory::write_information_to_file(objects_vector & objects, std::string new_filename){
    if( input.is_open() ){
        input.close();
    }
    output.open (new_filename+".properties");
    output << "SPAWN (" << spawn.x << ',' << spawn.y << ")\n";
    output << "LEVEL_SIZE (" << level_size.x << ',' << level_size.y << ")\n";
    
    for (const auto & object : objects){
        if (object->get_type() != "BORDER" && object->get_type() != "LOWER_BORDER"){
            output << object->object_information() + '\n';
        }
    }
    output.close();
}

sf::Vector2f factory::get_spawn(){
    return spawn;
}

sf::Vector2f factory::get_level_size(){
    return level_size;
}

std::ifstream & operator >> (std::ifstream & input, sf::Vector2f & rhs) { //space toevoegen achter ,?
	char c;
	if ( !(input >> c) ) { throw end_of_file(); }
	if ( c != '(' ) { throw invalid_position(c); }

	if ( !(input >> rhs.x) ) { throw invalid_position(); }
        
        input >> c;
	if ( c != ',' ) { throw invalid_position(c); }
	if ( !(input >> rhs.y) ) { throw invalid_position(); }
        
        input >> c;
	if ( c != ')' ) { throw invalid_position(c); }

	return input;
}

std::ifstream & operator >> (std::ifstream & input, sf::Color & rhs) {
	std::string name;
	input >> name;
	const struct { const char * name; sf::Color color; } colors[]{
		{ "yellow", sf::Color::Yellow },
		{ "red", sf::Color::Red },
		{ "blue", sf::Color::Blue },
		{ "black", sf::Color::Black },
		{ "cyan", sf::Color::Cyan },
		{ "green", sf::Color::Green },
		{ "magenta", sf::Color::Magenta },
		{ "transparent", sf::Color::Transparent },
                { "white", sf::Color::White },
                { "brown", sf::Color{165, 42, 42}}
	};
	for (auto const & color : colors) {
		if (color.name == name) {
			rhs = color.color;
			return input;
		}
	}
	if (name == "") { throw end_of_file(); }
	throw unknown_color( name );
	return input;
}