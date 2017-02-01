#include "soundtrack.hpp"
#include <iostream>
#include <string>
#include <SFML/Audio.hpp>



soundtrack::soundtrack(std::string filename){
	if (!sfmlmusic.openFromFile(filename)) {
		throw audio_load_error{ filename };
	}

}



void soundtrack::playmusic() {
		sfmlmusic.setLoop(1);
		sfmlmusic.play();
}

void soundtrack::playsound() {
	sfmlmusic.play();
};
