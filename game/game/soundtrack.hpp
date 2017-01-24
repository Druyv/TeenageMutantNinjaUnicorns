///@file

/*!
* \file soundTrack.hpp
*
* \author Luke Roovers
* \date	23-1-2017
*
* soundTrack class
*/

#ifndef _MUSIC_HPP
#define _MUSIC_HPP


#include <SFML\Graphics.hpp>
#include <SFML\audio.hpp>
#include <iostream>
#include <string>
/*!
* \class soundTrack
*
* \brief Class that plays either music or sound effects. 
*
* class with two functions to play either a sound effect or a music track.
* 
*
* \date 23/01/17
*/
class soundTrack {
public:
	/*! soundTrack()
	* \brief constructor for music player 
	*
	* default constructor to make the music/sound player
	*/
	soundTrack();
	/*!void PlayMusic(std::string str) 
	* \brief Music player
	*
	* Loads the specified music file and plays it. 
	*
	* \param[in] str		String that contains the song name+type
	*/
	void PlayMusic(std::string filename);
	/*!void PlayMusic(std::string str)
	* \brief Sound player
	*
	* Loads the specified sound file and plays it.
	*
	* \param[in] str		String that contains the sound name+type
	*/
	void PlaySound(std::string filename);

private:
	sf::Music SFMLmusic;
	sf::SoundBuffer buffer;
};
#endif

