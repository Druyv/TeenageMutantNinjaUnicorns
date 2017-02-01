#include "cutscene1.hpp"
#include "textbox.hpp"
#include "image.hpp"


cutscene1::cutscene1(sf::RenderWindow & window) :
	window(window),
        textbox1("What a magical day in the enchanted for-", "headshotArno.png", window),
	textbox2("*Sigh* This is why I drink...", "headshotArno.png", window),
	textbox3("DAD! DAD! ", "juniorhead.png", window),
	textbox4("JUNIOR! Where are your colors?! ", "headshotArno.png", window),
	textbox5("Frank got them! ", "juniorhead.png", window),
	textbox6("FrraaaaaanNNKKKKKKKKKK!!!!! ", "headshotArno.png", window),
	textbox7("Junior, tell your mom to wait with dinner! ", "headshotArno.png", window),
	textbox8("Mom is at the new neighbour, the tall, rich and single unicorn with the big horn! ", "juniorhead.png", window),
	textbox9("DINKKLEEEBERRGGGGG!! ", "headshotArno.png", window),
        background_angryarno(sf::Vector2f((0), (0)), "angryarno.png"),
	background_zoomedin(sf::Vector2f((0), (0)), "zoomedin.png"),
        background_construction(sf::Vector2f((0), (0)), "construction.png"),
        background_forest(sf::Vector2f((0), (0)),"background2.png"),
	Arno(sf::Vector2f((window.getSize().x*0.30), (window.getSize().y*0.56)),"Arno.png"),
	Junior(sf::Vector2f((window.getSize().x*0.50), (window.getSize().y*0.61)), "Junior3.png")
{
	background_forest.set_repeated(true);
	background_forest.set_scale(1, 1);
	background_forest.setTextureRect({ 0, 0, (int)background_forest.get_size().x*2, (int)background_forest.get_size().y });
	background_forest.set_smooth(true);

}

void cutscene1::play_scene() {
	scene1();
	window.display();
	sf::sleep(sf::seconds(3));
	window.clear();

	scene2();
	window.display();
	sf::sleep(sf::seconds(2));
	window.clear();

	scene3();
	window.display();
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
	window.clear();


}

void cutscene1::scene1() {
	background_forest.draw(window);
	Arno.draw(window);
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
	Arno.draw(window);
	Junior.draw(window);
	textbox3.draw(window);
}

void cutscene1::scene5() {
	background_forest.draw(window);
	Arno.draw(window);
	Junior.draw(window);
	textbox4.draw(window);
}

void cutscene1::scene6() {
	background_forest.draw(window);
	Arno.draw(window);
	Junior.draw(window);
	textbox5.draw(window);
}

void cutscene1::scene7() {
	background_angryarno.draw(window);
	textbox6.draw(window);
}

void cutscene1::scene8() {
	background_forest.draw(window);
	Arno.draw(window);
	Junior.draw(window);
	textbox7.draw(window);
}

void cutscene1::scene9() {
	background_forest.draw(window);
	Arno.draw(window);
	Junior.draw(window);
	textbox8.draw(window);
}

void cutscene1::scene10() {
	background_angryarno.draw(window);
	textbox9.draw(window);
}

