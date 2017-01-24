///@file

#ifndef FACTORY_HPP
#define FACTORY_HPP

#include "wall.hpp"
#include "unicorn.hpp"
#include <fstream>

/// \class invalid_position
///
/// \brief invalid position exception
///
/// This class can be used to generate a exception
/// when a incorrect position has been received using
/// input from a file
/// 
///
/// \date 23-1-2017
class invalid_position : public std::exception {
public:
	invalid_position(const char c) :
		msg{ std::string{ "Invalid position: " } +c }
	{}

	invalid_position() :
		msg{ "Invalid position" }
	{}
	const char * what() const noexcept override {
		return msg.c_str();
	}
private:
	std::string msg;
};

class end_of_file : public std::exception {
public:
	end_of_file() :
		msg{ std::string{ "Finished reading items from file" } }
	{}
	const char * what() const noexcept override {
		return msg.c_str();
	}
private:
	std::string msg;
};

class unknown_color : public std::exception {
public:
	unknown_color(const std::string color) :
		msg{ std::string{ "Unknown color: " } +color }
	{}
	const char * what() const noexcept override {
		return msg.c_str();
	}
private:
	std::string msg;
};

class unknown_type : public std::exception {
public:
	unknown_type(const std::string type) :
		msg{ "Unknown type: " + type }
	{}
	const char * what() const noexcept override {
		return msg.c_str();
	}
private:
	std::string msg;
};

std::ifstream & operator >> (std::ifstream & input, sf::Vector2f & rhs);
std::ifstream & operator >> (std::ifstream & input, sf::Color & rhs);

class factory {
private:
	int file_line_counter = 1;
	std::ifstream input;
	std::ofstream output;
public:
	factory(std::string filename);
	void change_input_to(std::string new_filename);
	object_ptr read_line();
	objects_vector objects_from_file();
	void write_information_to_file(objects_vector & objects, std::string new_filename);
};

#endif //FACTORY_HPP
