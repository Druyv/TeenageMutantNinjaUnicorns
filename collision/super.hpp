#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <functional>

class  super;

class action {
private:
	std::function< bool() > condition;
	std::function< void(super &) > work;
public:

  
	action( char & check, char & c, std::function< void(super &) > work ) :
		condition( [& ] () -> bool {
           return  check == c;}
		),
    work(work)
    {}

	action(
	   std::function< bool() > condition,
	   std::function< void(super &) > work
	) : condition( condition ),
		work( work )
	{}

	action(
		sf::Keyboard::Key key,
		std::function< void(super &) > work
	) :
		condition(
			[ key ]()->bool { return sf::Keyboard::isKeyPressed( key ); }
		),
		work(work)
	{}

	action(
		sf::Mouse::Button button,
		std::function< void(super &) > work
	) :
		condition(
			[ button ]()->bool { return sf::Mouse::isButtonPressed( button ); }
		),
		work(work)
	{}


	/*void operator()(){
		if( condition() ){
			work();
		}
	}*/
    	void operator()(super & object){
		if( condition() ){
			work(object);
		}
	}
};



class super {
public:
	bool within(float x, float a, float b) {
		return (x >= a) && (x <= b);
	}
 
  
    
 void jump(sf::Vector2f target){
        position+=target;
        
 
 }

 void run_actions(super & object){
     for (auto  & gh : actionlist){
         gh(object);
         
     }
     
 }
 
 

    super(sf::Vector2f  position = sf::Vector2f{0,0}, sf::Vector2f  size= sf::Vector2f{0,0},std::vector<action> actionlist = {}):
    position(position),size(size),actionlist(actionlist){}



    char collaps(super & object){
        
        if ((within(position.x, object.position.x, (object.position.x+object.size.x)) )and( (position.y==object.position.y) or (position.y +size.y==object.position.y))){
          
  return  'U';
        }
        else if ((within(position.x, object.position.x, (object.position.x+object.size.x)) )and(( position.y==(object.position.y+object.size.y) or (position.y +size.y==object.position.y)))){
                return 'D';
        }
        else if ((within(position.y, object.position.y, (object.position.y+object.size.y)) )and(( position.x+size.x == object.position.x)or (position.x +size.x==object.position.x+object.size.x))){

                return 'R';
        }
        else if ((within(position.y, object.position.y, (object.position.y+object.size.y)) )and(( position.x == object.position.x+object.size.x)or (position.x==object.position.x))){
            std::cout<<"hiero";
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

