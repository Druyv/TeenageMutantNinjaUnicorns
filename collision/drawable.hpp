#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <functional>



class  drawable;

class action {
private:
	std::function< bool() > condition;
	std::function< void(drawable &) > work;
public:

  
	action( char & check, char & c, std::function< void(drawable &) > work ) :
		condition( [& ] () -> bool {
           return  check == c;}
		),
    work(work)
    {}

	action(
	   std::function< bool() > condition,
	   std::function< void(drawable &) > work
	) : condition( condition ),
		work( work )
	{}

	action(
		sf::Keyboard::Key key,
		std::function< void(drawable &) > work
	) :
		condition(
			[ key ]()->bool { return sf::Keyboard::isKeyPressed( key ); }
		),
		work(work)
	{}

	action(
		sf::Mouse::Button button,
		std::function< void(drawable &) > work
	) :
		condition(
			[ button ]()->bool { return sf::Mouse::isButtonPressed( button ); }
		),
		work(work)
	{}



    	void operator()(drawable & object){
		if( condition() ){
			work(object);
		}
	}
};

/*!
 * \class drawable
 *
 * \brief class that is inherited by all objects that are drawable
 *
 * class with a position, size  and std::vector<action> , that is inherited by all 
 * object that can be drawn on the screen. 
 *
 * \date 20/01/17
 */

class drawable {
public:
/*! drawable(const sf::Vector2f & position, const sf::Vector2f & size, std::vector<action> actionlist )
	* \brief constructor for a drawable
	*
	* constructor that initializes position, size and actionlist of drawable
	*
	* \param[in] position		position of drawable, this is a sf::Vector2f and const
	* \param[in] size			size of drawable, this is a sf::Vector2f and const
	* \param[in] actionlist			this is the list of actions needed for reactions , this  is  an std::vector <action>
	*/
  drawable(sf::Vector2f  position = sf::Vector2f{0,0}, sf::Vector2f  size= sf::Vector2f{0,0},std::vector<action> actionlist = {});


	/*! bool within(float x ,float a , float b  )
	* \brief  if float x is in rang a:b,
	*
	* function that checks if  float x is bigger then float a and is smaller then float b)
	*
	* \param[in] x			    float that  will be checked with
    *  \param[in] a			float that will be used as the lowest point  of the range 
    *  \param[in] b			float that will be used as the highest point of the range 
	*/

	bool within(float x, float a, float b);
    	/*! bool within_range (float x,float y,float a , float b)
	* \brief  if  a float in range x:y  lays between range a:b,
	*
	* function that checks if  a float in range x to y lays between range a to b bij using the within function 
	*
	*  \param[in] x			    float that will be used as the lowest point of the first range
	*  \param[in] y				float that will be used as the highest point of the first range 
    *  \param[in] a				float that will be used as the lowest point  of the second  range 
    *  \param[in] b				float that will be used as the highest point of the secon range 
	*/
    
    bool within_range(float x, float y,float a, float b);
     	/*! bool move(sf::Vector2f target )
	* \brief  move object by target
	*
	* function that moves the object by target by appling the target to the position 
	*
	* \param[in] target		    sf::Vector2f that will me applied to the position to move the object

	*/

    
    void move(sf::Vector2f target);
      	/*! void run_action(drawable & object )
	* \brief   run  the actions out the actionlist
	*
	* function that  runs  trought the  actionlist  and runs each action .
	*
	* \param[in] object         drawable that needed bij the action class 

	*/


  void run_actions(drawable & object);
      	/*! char collapse(drawable & object )
	* \brief   collapse function that checks if this drawable collapse with  object 

	* function that  checks if this drawable  collapse with   object drawable
	* and  gives back a char that  has to propose  the side of colllapse 
	* \param[in] object         drawable where collapse  with  will be checked  

	*/
  

    char collapse(drawable & object);
    /*! virtual void draw(sf::RenderWindow & window)
	* \brief virtual draw function for a drawable
	*
	* virtual function that is defined in the subclasses of drawable
	*
	* \param[in] window			SFML window that is used to display the drawable 
	*/
        
    virtual void draw(sf::RenderWindow & window) = 0;

protected:
	
    sf::Vector2f position;
    sf::Vector2f size;
    std::vector<action> actionlist;
};

