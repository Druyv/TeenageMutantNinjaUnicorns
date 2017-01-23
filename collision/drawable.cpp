#include "drawable.hpp"

 drawable::drawable(sf::Vector2f  position, sf::Vector2f  size,std::vector<action> actionlist ):
        position(position),size(size),actionlist(actionlist){}
	
    
bool drawable::within(float x, float a, float b) {
		return (x >= a) && (x <= b);
    }
    
bool drawable::within_range(float x, float y,float a, float b){
        for (float i  = x+1;i<y;i++){
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
 
 char drawable::collision(drawable & object){
     bool within_x = within_range(position.x,position.x+size.x, object.position.x, (object.position.x+object.size.x));
     bool within_y = within_range(position.y,position.y+size.y,object.position.y,object.position.y+object.size.y) ;
     sf::Vector2f ob_position = object.position;
     sf::Vector2f ob_size = object.size;
        if ((within_x )and within(ob_position.y,position.y,position.y+size.y)){
              return  'U';
        }
        else if ((within_x)and within(ob_position.y+ob_size.y,position.y,position.y+size.y)){
                return 'D';
        }
        else if ((within_y)and within (position.x+size.x,ob_position.x , ob_position.x + ob_size.x)){
                return 'R';
        }
        else if ((within_y )and within(position.x, ob_position.x,ob_position.x + ob_size.x)){
                return 'L';
        }
    return 'X';
    }