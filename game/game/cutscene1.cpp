#include "cutscene1.hpp"


cutscene1::cutscene1(sf::RenderWindow & window,soundtrack & sound) :
    window{window},
    sound{sound},
    textbox1{"What a magical day in the enchanted for-", "headshotArno.png", window},
    textbox2{"*Sigh* This is why I drink...", "headshotArno.png", window},
    textbox3{"DAD! DAD! ", "juniorhead.png", window},
    textbox4{"JUNIOR! Where are your colors?! ", "headshotArno.png", window},
    textbox5{"Frank got them! ", "juniorhead.png", window},
    textbox6{"FrraaaaaanNNKKKKKKKKKK!!!!! ", "headshotArno.png", window},
    textbox7{"Junior, tell your mom to wait with dinner! ", "headshotArno.png", window},
    textbox8{"Mom is at the new neighbour, the tall, rich and single unicorn with the big horn! ", "juniorhead.png", window},
    textbox9{"DINKKLEEEBERRGGGGG!! ", "headshotArno.png", window},
    textbox_cyan1{"Hey Steff, I've got a very important mission for you! ", "headshotArno.png", window},
    textbox_cyan2{"It's Steve. ", "headshotSteve.png", window},
    textbox_cyan3{"Yes, Kevin. About that mission.  ", "headshotArno.png", window},
    textbox_cyan4{"It's Steve. ", "headshotSteve.png", window},
    textbox_cyan5{"Yes, Victor. You are going to Cyan Island. ", "headshotArno.png", window},
    textbox_cyan6{"It's Steve. Why aren't you going? ", "headshotSteve.png", window},
    textbox_cyan7{"Because, Gerald, it's a silly place. Good luck & have fun! ", "headshotArno.png", window},
    background_cyan{sf::Vector2f{(0), (0)}, "bcyan.png"},
    background_angryarno{sf::Vector2f{(0), (0)}, "angryArno.png"},
    background_zoomedin{sf::Vector2f{(0), (0)}, "zoomedin.png"},
    background_construction{sf::Vector2f{(0), (0)}, "construction.png"},
    background_forest{sf::Vector2f{(0), (0)},"background2.png"},
    arno{sf::Vector2f{(float)(window.getSize().x*0.30), (float)(window.getSize().y*0.56)},"Arno.png"},
    junior{sf::Vector2f{(float)(window.getSize().x*0.50), (float)(window.getSize().y*0.61)}, "Junior3.png"}
{
    background_forest.set_repeated(true);
    background_forest.set_scale(1, 1);
    background_forest.setTextureRect({ 0, 0, (int)background_forest.get_size().x*2, (int)background_forest.get_size().y });
    background_forest.set_smooth(true);
}

void cutscene1::play_scene() {
    scene1();
    window.display();
    sound.playsound_cutscene("scene1.wav");
    sf::sleep(sf::seconds(6));
    window.clear();
    
    scene2();
    window.display();
    sound.playsound_cutscene("scene2.wav");
    sf::sleep(sf::seconds(6));
    window.clear();
    
    scene3();
    window.display();
    sound.playsound_cutscene("scene3.wav");
    sf::sleep(sf::seconds(3));
    window.clear();
    
    scene4();
    window.display();
    sf::sleep(sf::seconds(3));
    window.clear();

    scene5();
    window.display();
    sf::sleep(sf::seconds(3));
    window.clear();

    scene6();
    window.display();
    sf::sleep(sf::seconds(3));
    window.clear();

    scene7();
    window.display();
    sf::sleep(sf::seconds(3));
    window.clear();

    scene8();
    window.display();
    sf::sleep(sf::seconds(3));
    window.clear();

    scene9();
    window.display();
    sf::sleep(sf::seconds(3));
    window.clear();

    scene10();
    window.display();
    sf::sleep(sf::seconds(4));
    sound.stop();
    window.clear();
}

void cutscene1::scene1() {
    background_forest.draw(window);
    arno.draw(window);
    textbox1.draw(window);
};

void cutscene1::scene2() {
    background_construction.draw(window);
}

void cutscene1::scene3() {
    background_zoomedin.draw(window);
    textbox2.draw(window);
}

void cutscene1::scene4() {
    background_forest.draw(window);
    arno.draw(window);
    junior.draw(window);
    textbox3.draw(window);
}

void cutscene1::scene5() {
    background_forest.draw(window);
    arno.draw(window);
    junior.draw(window);
    textbox4.draw(window);
}

void cutscene1::scene6() {
    background_forest.draw(window);
    arno.draw(window);
    junior.draw(window);
    textbox5.draw(window);
}

void cutscene1::scene7() {
    background_angryarno.draw(window);
    textbox6.draw(window);
}

void cutscene1::scene8() {
    background_forest.draw(window);
    arno.draw(window);
    junior.draw(window);
    textbox7.draw(window);
}

void cutscene1::scene9() {
    background_forest.draw(window);
    arno.draw(window);
    junior.draw(window);
    textbox8.draw(window);
}

void cutscene1::scene10() {
    background_angryarno.draw(window);
    textbox9.draw(window);
}

void cutscene1::scene11() {
    background_cyan.draw(window);
    textbox_cyan1.draw(window);
}

void cutscene1::scene12() {
    background_cyan.draw(window);
    textbox_cyan2.draw(window);
}

void cutscene1::scene13() {
    background_cyan.draw(window);
    textbox_cyan3.draw(window);
}

void cutscene1::scene14() {
    background_cyan.draw(window);
    textbox_cyan4.draw(window);
}

void cutscene1::scene15() {
    background_cyan.draw(window);
    textbox_cyan5.draw(window);
}

void cutscene1::scene16() {
    background_cyan.draw(window);
    textbox_cyan6.draw(window);
}

void cutscene1::scene17() {
    background_cyan.draw(window);
    textbox_cyan7.draw(window);
}

void cutscene1::cyan_island() {
    sound.stop_music();
    sound.playsound_cutscene("cyan.wav");
    scene11();
    window.display();
    sf::sleep(sf::seconds(3));
    window.clear();

    scene12();
    window.display();
    sf::sleep(sf::seconds(3));
    window.clear();

    scene13();
    window.display();
    sf::sleep(sf::seconds(3));
    window.clear();

    scene14();
    window.display();
    sf::sleep(sf::seconds(3));
    window.clear();

    scene15();
    window.display();
    sf::sleep(sf::seconds(3));
    window.clear();

    scene16();
    window.display();
    sf::sleep(sf::seconds(3));
    window.clear();

    scene17();
    window.display();
    sf::sleep(sf::seconds(3));
    window.clear();
    sound.stop();
    sound.playmusic();
}