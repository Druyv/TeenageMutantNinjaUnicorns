#include "textbox.hpp"

textbox::textbox(std::string string, std::string filename, sf::RenderWindow & window):
	string(string),
	window(window),
	filename(filename)
	

{
	texture.loadFromFile("textbox.png");
	texture2.loadFromFile(filename);
	position = sf::Vector2f(0, (window.getSize().y*0.75));
	BoxBackground.setTexture(&texture);
	HeadBox.setTexture(&texture2);
	build_box();
}

void textbox::build_box() {

	BoxBackground.setPosition(position);
	BoxBackground.setSize(sf::Vector2f(float(window.getSize().x), float(window.getSize().y*0.2) ));

	float posx = position.x *1.05;
	float posy = position.y *1.05;
	HeadBox.setPosition(sf::Vector2f(posx+15,posy*0.98));
	HeadBox.setSize(sf::Vector2f(BoxBackground.getSize().x*0.1, BoxBackground.getSize().y*0.80));

	font.loadFromFile("ArchitectsDaughter.ttf");
	text.setFont(font);
	text.setString(string);
	text.setFillColor(sf::Color::Black);


	text.setCharacterSize(24);

	sf::Vector2f positionbox = sf::Vector2f(BoxBackground.getPosition());
	float ding = ((positionbox.x)+300);
	text.setPosition((ding),(positionbox.y*1.1));
}


void textbox::draw(sf::RenderWindow & window1) {
	window1.draw(BoxBackground);
	window1.draw(HeadBox);
	window1.draw(text);
}
