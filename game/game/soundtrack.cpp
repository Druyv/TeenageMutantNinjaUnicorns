#include "soundtrack.hpp"
#include <iostream>
#include <string>
#include <SFML/Audio.hpp>



soundtrack::soundtrack(std::string filename){
	if (!SFMLmusic.openFromFile(filename)) {
		throw audio_load_error{ filename };
	}

}



void soundtrack::playmusic() {
		SFMLmusic.setLoop(1);
		SFMLmusic.play();
}

