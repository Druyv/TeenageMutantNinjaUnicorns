#include "soundtrack.hpp"
#include <iostream>
#include <string>
#include <SFML/Audio.hpp>



soundtrack::soundtrack(std::string filename){
	if (!sfmlmusic.openFromFile(filename)) {
		throw audio_load_error{ filename };
	}
sfmlmusic.setLoop(1);
}



void soundtrack::playmusic() {
		
		sfmlmusic.play();
}

void soundtrack::playsound(std::string name){
sfmlmusic.pause();
sound.openFromFile(name);
std::cout<<name;
sound.play();
sfmlmusic.play();
}

void soundtrack::playsound_cutscene(std::string name){

sound.openFromFile(name);

sound.play();

}
void soundtrack::stop(){
sound.pause();
}
