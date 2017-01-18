#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
class super {
public:
	bool within(float x, float a, float b) {
		return (x >= a) && (x <= b);
	}
 
  
    
 void jump(sf::Vector2f target){
        position+=target;
 
 }

 

    super(sf::Vector2f & position, sf::Vector2f & size):
    position(position),size(size){}



    char collaps(super & object){
        if ((within(position.x, object.position.x, (object.position.x+object.size.x)) )and( position.y==object.position.y)){
            return  'U';
        }
        else if ((within(position.x, object.position.x, (object.position.x+object.size.x)) )and( position.y==(object.position.y+object.size.y))){
            return 'D';
        }
        else if ((within(position.y, object.position.y, (object.position.y+object.size.y)) )and( position.x == object.position.x+object.size.x)){
            return 'R';
        }
        else if ((within(position.y, object.position.y, (object.position.y+object.size.y)) )and( position.x == object.position.x)){
            return 'L';
        }
        return 'X';
    }
        
        
        

protected:
	 virtual void draw(sf::RenderWindow & window) = 0;
		  sf::Vector2f position;
    sf::Vector2f size;
};

