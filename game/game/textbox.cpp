#include "textbox.hpp"

textbox::textbox(std::string string, std::string filename, sf::RenderWindow & window):
    string{string},
    window{window},
    filename{filename}
{
    texture.loadFromFile("textbox.png");
    texture2.loadFromFile(filename);
    position = sf::Vector2f(0, (window.getSize().y*0.75));
    box_background.setTexture(&texture);
    head_box.setTexture(&texture2);
    build_box();
}

void textbox::build_box() {
    box_background.setPosition(position);
    box_background.setSize(sf::Vector2f(float(window.getSize().x), float(window.getSize().y*0.2) ));

    float posx = position.x *1.05;
    float posy = position.y *1.05;
    head_box.setPosition(sf::Vector2f(posx+15,posy*0.98));
    head_box.setSize(sf::Vector2f(box_background.getSize().x*0.1, box_background.getSize().y*0.80));

    font.loadFromFile("ArchitectsDaughter.ttf");
    text.setFont(font);
    text.setString(string);
    text.setFillColor(sf::Color::Black);


    text.setCharacterSize(24);

    sf::Vector2f positionbox = sf::Vector2f(box_background.getPosition());
    float textoffset = ((positionbox.x)+300);
    text.setPosition((textoffset),(positionbox.y*1.1));
}


void textbox::draw(sf::RenderWindow & window1) {
    window1.draw(box_background);
    window1.draw(head_box);
    window1.draw(text);
}
