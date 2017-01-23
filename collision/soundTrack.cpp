#include "soundTrack.hpp"
#include <iostream>
#include <string>
#include <SFML\audio.hpp>


soundTrack::soundTrack()
{}



void soundTrack::PlayMusic(std::string str) {
	std::string path = "C:\\game\\game\\Debug\\";
	std::string ConstructedPath = path + str;
	
	if (SFMLmusic.openFromFile(ConstructedPath)) {
		SFMLmusic.setLoop(1);
		SFMLmusic.play();

	}
	std::cout << "File not found";
}

void soundTrack::PlaySound(std::string str) {
	std::string path = "C:\\game\\game\\Debug\\";
	std::string ConstructedPath = path + str;
	if (buffer.loadFromFile(ConstructedPath) ){
		SFMLmusic.play();
	}
	std::cout << "File not found // Can't open file ";
};
