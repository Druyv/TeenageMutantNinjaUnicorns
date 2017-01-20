#include "drawable.hpp"

 drawable::drawable(sf::Vector2f  position, sf::Vector2f  size,std::vector<action> actionlist ):
        position(position),size(size),actionlist(actionlist){}
	
    
bool drawable::within(float x, float a, float b) {
		return (x >= a) && (x <= b);
    }
    
bool drawable::within_range(float x, float y,float a, float b){
        for (float i  = x;i<y;i++){
            if (within(i,a,b)){
                return true;
            }
        }
        return false;
    }
    
    
void drawable::move(sf::Vector2f target){
        position+=target;
 }
 
void drawable::run_actions(drawable & object){
     for (auto  & g : actionlist){
         g(object);
     }
 }
 
 char drawable::collapse(drawable & object){
        
        if ((within_range(position.x,position.x+size.x, object.position.x, (object.position.x+object.size.x)) )and( (position.y==object.position.y) or (position.y +size.y==object.position.y))){
                return  'U';
        }
        else if ((within_range(position.x,position.x+size.x, object.position.x, object.position.x+object.size.x) )and(( position.y==(object.position.y+object.size.y) or (position.y +size.y==object.position.y)))){
                return 'D';
        }
        else if ((within_range(position.y,position.y+size.y,object.position.y,object.position.y+object.size.y)  )and(( position.x+size.x == object.position.x)or (position.x +size.x==object.position.x+object.size.x))){
                return 'R';
        }
        else if ((within_range(position.y,position.y+size.y, object.position.y, (object.position.y+object.size.y)) )and(( position.x == object.position.x+object.size.x)or (position.x==object.position.x))){
                return 'L';
        }
    return 'X';
    }