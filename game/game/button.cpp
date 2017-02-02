#include "button.hpp"


button::button(float start_height_y, float start_height_x, int position, std::string whats_on_the_button) :
    start_height_y{start_height_y},
    start_height_x{start_height_x},
    position{position},
    whats_on_the_button{whats_on_the_button}
{
    setup();
}



void button::setup() {
    texture.loadFromFile("button.png");
    button_background.setTexture(&texture);
    button_background.setSize((sf::Vector2f)texture.getSize());

    float interval = -150;
    if (position == 2) { interval+=button_background.getSize().y; }
    else if (position == 3) { interval+=2*button_background.getSize().y; }

    button_background.setPosition(
        ((start_height_x-button_background.getSize().x)/2),
        ((start_height_y-button_background.getSize().y)/2)+interval
    );
    
    font.loadFromFile("Pixeled.ttf");
    text.setFont(font);
    text.setString(whats_on_the_button);
    text.setCharacterSize(60*texture.getSize().y/200);
    text.setFillColor(sf::Color::Black);

    sf::Vector2f button_pos = (sf::Vector2f)button_background.getPosition();
    sf::Vector2f button_size = (sf::Vector2f)texture.getSize();

    sf::Vector2f text_position {
        button_pos.x + (button_size.x-text.getLocalBounds().width) /2,
        button_pos.y + (button_size.y-text.getLocalBounds().height) /2
    };

    text.setPosition(text_position);
}

sf::FloatRect button::getGlobalBounds() {
    return button_background.getGlobalBounds();
}


void button::draw(sf::RenderWindow & window) {
    window.draw(button_background);
    window.draw(text);
};