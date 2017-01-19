#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "action.hpp"
class super {
public:
	bool within(float x, float a, float b) {
		return (x >= a) && (x <= b);
	}
 
  
    
 void jump(sf::Vector2f target){
        position+=target;
 
 }

 void run_actions(){
     for (auto  & gh : actionlist){
         gh();
         
     }
     
 }
 
 

    super(sf::Vector2f  position = sf::Vector2f{0,0}, sf::Vector2f  size= sf::Vector2f{0,0},std::vector<action> actionlist = {}):
    position(position),size(size),actionlist(actionlist){}



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
        
        
         virtual void draw(sf::RenderWindow & window) = 0;

protected:
	
		  sf::Vector2f position;
    sf::Vector2f size;
    std::vector<action> actionlist;
};

