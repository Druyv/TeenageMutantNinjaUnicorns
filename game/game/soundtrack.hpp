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
	/// \ brief  stop the background music
	///
	//
	void stop_music();
	
	///\brief Music player
	///
	/// Loads the specified music file and plays it. 
        ///
	void playmusic();
	/// \brief Sound player
	///
	/// Loads the specified sound file and plays it.
    ///
	/// \param[in] name  name of file 
	void playsound(std::string name);
	/// \brief stop the sound that is playing
	void stop();
	/// \brief play a sound for in the cutscene
	///
	///  this is a playfunction without collision  with the background music.
	///
	/// \param[in] name name of file that wants to play 
	
	void playsound_cutscene(std::string name);
private:
	sf::Music sfmlmusic;
	sf::Music sound;
	

};
#endif

