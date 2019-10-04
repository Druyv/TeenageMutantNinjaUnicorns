///@file

#ifndef CUTSCENE1_HPP
#define CUTSCENE1_HPP

#include <SFML/Graphics.hpp>
#include <iostream>

#include "soundtrack.hpp"
#include "textbox.hpp"
#include "image.hpp"

/// \class cutscene1
///
/// \brief Creates a cutscene ( the opening scenes/steve scene )
///
/// This class is used to make a cutscene that is showed
/// on the screen. It consists of the opening scenes and 
/// the Steve scene. 
///  
///
/// \date 2-2-2017
class cutscene1 {
    private:
	sf::RenderWindow & window;
	soundtrack & sound;
	textbox textbox1;
	textbox textbox2;
	textbox textbox3;
	textbox textbox4;
	textbox textbox5;
	textbox textbox6;
	textbox textbox7;
	textbox textbox8;
	textbox textbox9;
        textbox textbox_cyan1;
        textbox textbox_cyan2;
        textbox textbox_cyan3;
        textbox textbox_cyan4;
        textbox textbox_cyan5;
        textbox textbox_cyan6;
        textbox textbox_cyan7;
        image_from_file background_cyan;
	image_from_file background_angryarno;
	image_from_file background_zoomedin;
	image_from_file background_construction;
	image_from_file background_forest;
	image_from_file arno;
	image_from_file junior;
    public:
        /// \brief constructor to initialize a cutscene
	///  
	///  The constructor uses the window to draw the  
	///  backgrounds and characters on the screen. 
	///  The soundplayer is used to play sound during the
	///  scene.
	///
	/// \param[in] window sf::renderwindow object
	/// \param[in] sound soundplayer object 
	cutscene1(sf::RenderWindow & window,soundtrack & sound);
        
        /// \brief Draws the opening scene  
	///
	/// Runs all the functions needed for the opening scene
        ///   
	void play_scene();
        
	/// \brief Draws the scene  
	///
	/// Draws all the things needed for the first scene
        /// (textbox, characters, background)   
	///
	void scene1();
        
        /// \brief Draws the scene  
	///
	/// Draws all the things needed for the first scene
        /// (textbox, characters, background)   
    	///
	void scene2();
        
        /// \brief Draws the scene  
	///
	/// Draws all the things needed for the first scene
        /// (textbox, characters, background)   
	///
	void scene3();
        
        /// \brief Draws the scene  
	///
	/// Draws all the things needed for the first scene
        /// (textbox, characters, background)   
	///
	void scene4();
        
        /// \brief Draws the scene  
	///
	/// Draws all the things needed for the first scene
        /// (textbox, characters, background)   
	///
	void scene5();
        
        /// \brief Draws the scene  
	///
	/// Draws all the things needed for the first scene
        /// (textbox, characters, background)   
	///
	void scene6();
        
        /// \brief Draws the scene  
	///
	/// Draws all the things needed for the first scene
        /// (textbox, characters, background)   
	///
	void scene7();
        
        /// \brief Draws the scene  
	///
	/// Draws all the things needed for the first scene
        /// (textbox, characters, background)   
	///
	void scene8();
        
        /// \brief Draws the scene  
	///
	/// Draws all the things needed for the first scene
        /// (textbox, characters, background)   
	///
	void scene9();
        
        /// \brief Draws the scene  
	///
	/// Draws all the things needed for the first scene
        /// (textbox, characters, background)   
	///
	void scene10();
        
        /// \brief Draws the scene  
	///
	/// Draws all the things needed for the first scene
        /// (textbox, characters, background)   
	///
	void scene11();
        
        /// \brief Draws the cyan scene  
	///
	/// Draws all the things needed for the first scene
        /// (textbox, characters, background)   
	///
	void scene12();
        
        /// \brief Draws the cyan scene  
	///
	/// Draws all the things needed for the first scene
        /// (textbox, characters, background)   
	///
	void scene13();
        
        /// \brief Draws the cyan scene  
	///
	/// Draws all the things needed for the first scene
        /// (textbox, characters, background)   
	///
	void scene14();
        
        /// \brief Draws the cyan scene  
	///
	/// Draws all the things needed for the first scene
        /// (textbox, characters, background)   
    	///
	void scene15();
        
        /// \brief Draws the cyan scene  
	///
	/// Draws all the things needed for the first scene
        /// (textbox, characters, background)   
	///
	void scene16();
        
        /// \brief Draws the cyan scene  
	///
	/// Draws all the things needed for the first scene
        /// (textbox, characters, background)   
	///
	void scene17();
        
        /// \brief Draws the Steve scene  
	///
	/// Runs all the functions needed for the steve scene
        ///   
	///
        void cyan_island();

        void skip_or_quit();
};
#endif //CUTSCENE1_HPP
