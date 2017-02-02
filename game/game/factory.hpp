///@file

#ifndef FACTORY_HPP
#define FACTORY_HPP

#include <fstream>

#include "wall.hpp"
#include "unicorn.hpp"
#include "exceptions.hpp"

std::ifstream & operator >> (std::ifstream & input, sf::Vector2f & rhs);
std::ifstream & operator >> (std::ifstream & input, sf::Color & rhs);

/// \class factory
///
/// \brief Factory for reading in levels
///
/// This class is for reading in levels using a factory pattern. It uses smart
/// pointers for making sure that destruction of the created heap objects is
/// done correctly.
/// \date 26-1-17
///
class factory {
    private:
	int file_line_counter = 1;
        std::ifstream input;
        std::ofstream output;
        sf::Vector2f spawn;
        sf::Vector2f level_size;
    public:
        /// \brief constructor input file
	///
	/// This constructor receives an input file to read the level out of.
        /// That level can be changed later to read in new levels using the 
        /// #factory::change_input_to() function. The received file name gets
        /// the .properties extension and a filestream object is created.
	///
	/// \param[in] filename The file to open as a filestream object
	/// \note The filename automatically gets the extension .properties
        ///
	factory(std::string filename);
        
        /// \brief Change the input
	///
	/// This function changes the input to a new specified file. It also
        /// closes the old file if it is open.
	///
	/// \param[in] new_filename The name of the new file to open
        ///
        void change_input_to(std::string new_filename);
        
        /// \brief Read one line from the filestream
	///
	/// This function reads one line from the filestream opened in the
        /// constructor. It returns a smart pointer to the object it received or
        /// a number of different kind of errors. The errors that can be thrown
        /// back are: #unknown_type, "LEVEL_SIZE" and "SPAWN". The level_size and
        /// spawn errors are for when the code receives the spawn and level size
        /// from the file it is reading. 
	///
	/// \return The shared pointer to the drawable object
        ///
        object_ptr read_line();
        
        /// \brief Read multiple objects
	///
	/// This function continuesly calls the #factory::read_line() function
        /// and fills an #objects_vector with #drawable objects. This filled
        /// vector is returned. The errors returned by the read_line() function
        /// are also handled in this function.
	///
	/// \return The vector with the created objects
        ///
        objects_vector objects_from_file();
        
        /// \brief Write information to file
	///
	/// This function writes all the information on the objects to an output
        /// file that is specified in the parameters. It first closes any input
        /// files and then opens the output file. After this it outputs the spawn
        /// location and level size calls the #drawable::object_information()
        /// function on every item in the vector. You end up with an output like
        /// this:
        /// SPAWN (1030,1500)
        /// LEVEL_SIZE (4000,3350)
        /// WALL (1020.000000,2000.000000) (100.000000,20.000000) green grass.png
	///
	/// \param[in] objects The #objects_vector that contains all the objects
        /// we want to write to the file
	/// \param[in] new_filename The file to write the information to
	///
        void write_information_to_file(objects_vector & objects, std::string new_filename);
        
        /// \brief Get spawn location
	///
	/// This function returns the spawn location for the level
	///
	/// \return The spawn location
        ///
        sf::Vector2f get_spawn();
        
        /// \brief Get the level size
	///
	/// This function returns the level size.
	///
	/// \return The level size
        ///
        sf::Vector2f get_level_size();
};
#endif //FACTORY_HPP
