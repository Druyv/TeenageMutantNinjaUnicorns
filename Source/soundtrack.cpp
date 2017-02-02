#include "soundtrack.hpp"

soundtrack::soundtrack(std::string filename){
    if (!sfmlmusic.openFromFile(filename)) {
        throw audio_load_error{ filename };
    }
}

void soundtrack::stop_music(){
    sfmlmusic.stop()	;
}


void soundtrack::playmusic() {
    sfmlmusic.setLoop(1);
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
