#include "bullet.hpp"

bullet::bullet(sf::Vector2f position, std::string image_name):
	image_bullet(image_from_file(position, image_name)),
	drawable(position,image_bullet.GetSize(), "Bullet")
{

}

void bullet::projectile() {
	image_bullet.move(sf::Vector2f(5.0f, 0.0f));
	/*Door lijst van collision heen loopen 
	if (collision){
		destroy mezelf. En trek levens af van het object waar ik tegenaan bots
		Als ik tegen een muur bots trek geen levens af.
	*/
}

void bullet::fire(sf::Vector2f fire_position) {
	image_bullet.SetPosition(fire_position);
}

void bullet::draw(sf::RenderWindow & window) {
	projectile();
	image_bullet.draw(window);
}