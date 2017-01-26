#include "animation.hpp"

#include "math.h"
animation::animation(sf::Vector2f position, std::string sheet_name) :
	drawable{ position, sf::Vector2f{ 0,0 }, "PICTURE" },
	sheet_name{ sheet_name }
{
	if (!texture.loadFromFile(sheet_name)) {
		throw sheet_load_error{ sheet_name };
	}

	sheet.setTexture(texture);
	size = (sf::Vector2f)texture.getSize();
        size = sf::Vector2f(size.x/7,size.y/5 );
}

void animation::draw(sf::RenderWindow & window) {
	sheet.setPosition(position);
        
     //   sheet.setTextureRect(sf::IntRect(count * (size.x) , row*(size.y+1), (size.x),(size.y )));
        if (rot==360){
                rot=0;
        }
      //  sheet.setRotation(rot+=(360/7));
        window.draw(sheet);
}
        
sf::FloatRect animation::getGlobalBounds() {
	return sheet.getGlobalBounds();
}

void animation::set_position(sf::Vector2f new_position) {
	position = new_position;
        	sheet.setPosition(position);
}

bool animation::movement(float row_a){


        if(row_a ==9){
        count = 0;
        rot =0;
        sheet.setRotation(0);
        sheet.setOrigin(0,0);
        return is_jumping;
        }
        else if(row_a==2){
                sheet.setOrigin((float)(size.x/2.5),(float)(size.y/2.5));
                sheet.setRotation(rot+=(float(360)/float(21.6)));
                is_jumping = true;
        }
        else if  (count==6 || row_a !=row){
                       row = row_a;
                        count = 0;
        }
        else {
                        count+=1;
        }


        sheet.setTextureRect(sf::IntRect(int(count * (size.x)) , int(row*(size.y+1)), int((size.x)),int(size.y )));
return 0;
}


void animation::set_size(sf::Vector2f new_size) {
	size = new_size;
}



void animation::setTextureRect(const sf::IntRect & rectangle) {
	sheet.setTextureRect(rectangle);
}