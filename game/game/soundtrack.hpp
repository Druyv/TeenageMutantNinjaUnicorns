///@file



#ifndef _MUSIC_HPP
#define _MUSIC_HPP


#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <string>



class audio_load_error : public std::exception {
public:
	/// \brief constructor
	///
	/// This constructor puts a message into a string and saves that as
	/// a private variable. The audio name is also added to the string.
	///
	/// \param[in] load_name The name of the image
	audio_load_error(const std::string & audio_name) :
		msg{ std::string{ "Can not load audio with name: " } +audio_name }
	{}

	/// \brief return message
	///
	/// This function returns the message so it can be printed.
	/// It overrides the what function from the std::exception
	/// superclass, making it easy to capture. 
	/// 
	/// \retval const char * {The error message as a const char *}
	const char * what() const noexcept override {
		return msg.c_str();
	}
private:
	std::string msg;
};



/// \class soundtrack
///
/// \brief Class that plays either music or sound effects. 
///
/// class with two functions to play either a sound effect or a music track.
/// 
///
/// 
///
class soundtrack {
public:
	/// \brief constructor for soundtrack class
	///
	/// constructor that initializes the file that the soundtrack class will use. 
	///
	/// \param[in] std::string		name of the file that will be loaded as a soundtrack
	
	/// \sa <a href="http://www.sfml-dev.org/documentation/2.0/classsf_1_1Music.php">sf::Music</a>
	soundtrack(std::string filename);
	

	///void PlayMusic(std::string str) 
	///\brief Music player
	///
	/// Loads the specified music file and plays it. 
	///
	///
	///
	void PlayMusic();
	///void PlayMusic(std::string str)
	/// \brief Sound player
	///
	/// Loads the specified sound file and plays it.
	///
	/// 
	///
	void PlaySound();

private:
	sf::Music SFMLmusic;

};
#endif

