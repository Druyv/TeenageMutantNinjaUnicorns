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
	float positionx;
	float positiony;
	if (position == 1) { (positionx = 0.20f) && (positiony = 0.27f); };
	if (position == 2) { (positionx = 0.40f) && (positiony = 0.47f); };
	if (position == 3) { (positionx = 0.60f) && (positiony = 0.67f); };

	texture.loadFromFile("button.png");
	ButtonBackground.setTexture(texture);
	texture.setSmooth(true);
	texture.setRepeated(0);

	ButtonBackground.setTextureRect(sf::IntRect(0, 0, (int(startHeightX*0.50)), int(startHeightY*0.20)));
	ButtonBackground.setPosition((startHeightX*0.33), (startHeightY*positionx));


	font.loadFromFile("Pixeled.ttf");
	text.setFont(font);
	text.setString(WhatsOnTheButton);
	text.setCharacterSize(60);
	text.setFillColor(sf::Color::Black);


	float positiontext = 0.50 - ((WhatsOnTheButton.size())*0.014);
	if ((WhatsOnTheButton.size()) > 7) {
		positiontext = 0.50 - ((WhatsOnTheButton.size())*0.0154);
	};
	text.setPosition((startHeightX*positiontext), (startHeightY*positiony));
}

sf::FloatRect Button::getGlobalBounds() {
	return ButtonBackground.getGlobalBounds();
}


void Button::draw(sf::RenderWindow & window) {

	window.draw(ButtonBackground);
	window.draw(text);
};