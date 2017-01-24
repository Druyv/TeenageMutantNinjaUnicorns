#include "soundTrack.hpp"
#include <iostream>
#include <string>
#include <SFML\audio.hpp>


soundTrack::soundTrack()
{}



void soundTrack::PlayMusic(std::string filename) {
	
	if (SFMLmusic.openFromFile(filename)) {
		SFMLmusic.setLoop(1);
		SFMLmusic.play();

	}
	std::cout << "File not found";
}

void soundTrack::PlaySound(std::string filename) {
	if (buffer.loadFromFile(filename) ){
		SFMLmusic.play();
	}
	std::cout << "File not found // Can't open file ";
};
