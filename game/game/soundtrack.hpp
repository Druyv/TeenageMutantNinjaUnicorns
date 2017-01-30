///@file

#ifndef _MUSIC_HPP
#define _MUSIC_HPP


#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <string>
#include "exceptions.hpp"

/// \class soundtrack
///
/// \brief Class that plays either music or sound effects. 
///
/// Class with two functions to play either a sound effect or a music track.
///
class soundtrack {
public:
	/// \brief constructor for soundtrack class
	///
	/// constructor that initializes the file that the soundtrack class will use. 
	///
	/// \param[in] std::string name of the file that will be loaded as a soundtrack
	///
	/// \sa <a href="http://www.sfml-dev.org/documentation/2.0/classsf_1_1Music.php">sf::Music</a>
        ///
	soundtrack(std::string filename);
	
	///\brief Music player
	///
	/// Loads the specified music file and plays it. 
        ///
	void playmusic();
        

private:
	sf::Music SFMLmusic;

};
#endif

