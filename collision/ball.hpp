#ifndef _BALL_HPP
#define _BALL_HPP

#include <SFML/Graphics.hpp>
#include "super.hpp"
#include "wall.hpp"
#include <math.h>
#include <iostream>
class ball: public super {
public:

	ball( sf::Vector2f position,sf::Vector2f size);

	void draw( sf::RenderWindow & window ) override;

	
    
    double functie(int n ){
        int x = n-14;
        if (x<0){
        return   -(-0.3 * (pow(x,2)) +60) +(-0.3 * (pow(x-1,2)) +60);
        }
        else{
                    return   (-0.3 * (pow(x-1,2)) +60)-(-0.3 * (pow(x,2)) +60);

            
        }
        }
    
    
    
    
    void spring(){
        for (int i =0;i<40;i++){
        jump(sf::Vector2f(1,functie(i)));
        std::cerr<<position.x <<"," <<position.y<<"\n";
        
    }
    }
	
	


private:
	
	
	

};

#endif
