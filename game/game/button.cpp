#include "button.hpp"


Button::Button(float startHeightY, float startHeightX,int position, std::string WhatsOnTheButton) :
	startHeightY(startHeightY),
	startHeightX(startHeightX),
	position(position),
	WhatsOnTheButton(WhatsOnTheButton)
{
	setup();
}



void Button::setup() {
	texture.loadFromFile("button.png");
	ButtonBackground.setTexture(&texture);
        ButtonBackground.setSize((sf::Vector2f)texture.getSize());
        
        float interval = -150;
        if (position == 2) { interval+=ButtonBackground.getSize().y; }
        else if (position == 3) { interval+=2*ButtonBackground.getSize().y; }
        
        
	ButtonBackground.setPosition( ((startHeightX-ButtonBackground.getSize().x)/2),
                ((startHeightY-ButtonBackground.getSize().y)/2)+interval );

	font.loadFromFile("Pixeled.ttf");
	text.setFont(font);
	text.setString(WhatsOnTheButton);
	text.setCharacterSize(60*texture.getSize().y/200);
	text.setFillColor(sf::Color::Black);
        
        sf::Vector2f button_pos = (sf::Vector2f)ButtonBackground.getPosition();
        sf::Vector2f button_size = (sf::Vector2f)texture.getSize();
        
        sf::Vector2f text_position { button_pos.x + (button_size.x-text.getLocalBounds().width) /2,  button_pos.y + (button_size.y-text.getLocalBounds().height) /2};
        
	text.setPosition(text_position);
}

sf::FloatRect Button::getGlobalBounds() {
	return ButtonBackground.getGlobalBounds();
}


void Button::draw(sf::RenderWindow & window) {
	window.draw(ButtonBackground);
	window.draw(text);
};