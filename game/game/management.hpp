///@file
#include <iostream>
#include <fstream>
#include "menu.hpp"
#include "cutscene1.hpp"



/// \class file_management
///
/// \brief file manager for the save-files
///
/// This class reads the save-files and gives back the 
/// path to the level in the save file. This function can also be used 
/// for loading the path to the level after the one your currently playing 
/// 
/// \date 30-1-17
///
class file_management {
private:
	
	std::ifstream input;
	std::ofstream output;
	std::string save_file_1;
	std::string save_file_2;
	int counter; 
	int current_save_file = 0;
	std::string standard_path = "levels/";
public:
	/// \brief constructor to initialize pathfile
	///
	/// This constructor sets input equal to the pathfile given.
	///
	/// \param[in] pathfile The pathfile that contains all save_file paths 
	///
	file_management(std::string pathfile);

	/// \brief function that changes input that is used for information
	///
	/// This function is used to change the std::ifstream to the given 
	/// file in the parameter
	///
	/// \param[in] new_filename Filepath you want to use as input file 
	///
	void set_input(std::string new_filename);

	/// \brief function that loads input from file
	///
	/// This function loads input from file that is used as input file.
	/// returns one line at the time.
	///
	/// \return std::string that is the content of the line of the file
	///
	std::string get_files();

	/// \brief function that returns path to level given save-file
	///
	/// This function gets the path of the level currently in the save-file,
	/// it also reads this string and determines which level the file is. Then 
	/// sets the counter to that level. 
	///
	/// \param[in] save_file path to file that contains path to level 
	///
	/// \return std::string that contains path to level in save_file
	///
	std::string get_level_file(std::string save_file);

	/// \brief function that rerturns menu-object
	///
	/// This function makes a menu containing the save-files. The size of 
	/// the menu depends on the amount of save-files. This function reads all
	/// save_files (it also saves them as a private variable) and determines how 
	/// many menu items it has to make. It returns the created menu.
	///
	/// \param[in] window sf::RenderWindow from SFML that is used to display the menu on
	///
	/// \return menu-object that is used in #menu_management
	///
	menu make_save_file_menu(sf::RenderWindow & window);

	/// \brief function that returns next level path 
	///
	/// This function return string ( that can be fabricated by standard_path
	/// and the counter) that is used as a path to the next level. 
	///
	/// \return std::string that contains path to next level
	///
	std::string next_level();

	/// \brief function that sets counter
	///
	/// This function sets counter to given value. 
	///
	/// \param[in] value integer you want to set value to 
	///
	void set_counter(int value);
        /// \brief getter for the counter of the level
		/// 
	/// returns the counter in reference so it makes the counter lookable every moment
        int & get_counter();

	/// \brief function that returns path to save-file given menu item pushed 
	///
	/// This function returns the path to the save-file of the given menu_index,
	/// for example: If the first menu item (in this game "SAVE 1") is pressed. 
	/// The menu_index is entered (1) and the return is the path to save file 1
	///
	/// \param[in] menu_index index of the menu button pressed. 
	///
	/// \return std::string that contains path to save-file
	///
	std::string get_save_file(int menu_index);

	/// \brief function that saves game
	///
	/// This function saves your current level path in a save-file. Which save file is used to 
	/// save the path in depends on the save-file clicked by the user in the beginning. If you 
	/// click "new game" the save-file is most of the time save-file-1 only when save-file-2 is 
	/// empty it is chosen to write in. 
	void save_game();
};

/// \class menu_management
///
/// \brief manager of all menu's in game 
///
///	Manager for the menu's available in the game  
///
/// \date 30-1-17
///
class menu_management {
private:

	sf::RenderWindow & window;
	file_management & manager;
	menu start_menu = menu(window,std::string{"forest.png"} , true, "NEW_GAME", true, "LOAD GAME", true, "QUIT" );
	menu pause_menu = menu(window, std::string{"forest.png"},true, "CONTINUE",true ,"QUIT");
	menu save_file_menu = manager.make_save_file_menu(window);
public:
	/// \brief constructor to initialize window and file manager
	///
	/// This constructor initializes the window where the menu's are displayed on.
	/// It also initializes the manager for the files
	///
	/// \param[in] window  sf::RenderWindow that is used to display menu's 
	/// \param[in] manager filemanagement-object that used to give functionality to menu's 
	///
	menu_management(sf::RenderWindow & window, file_management & manager);
	/// \brief function that displays start_menu
	///
	/// This function is used to display the start_menu
	///
	/// \return menu item that is pressed
	///
	int display_start_game();
	/// \brief function that displays pause_menu
	///
	/// This function displays the pause menu
	///
	/// \note This function doesn't have a return value, because of a bug this function doesn't have much functionality
	///
	void display_pause_game();
	/// \brief function that displays the save_file_menu 
	///
	/// FThis function displays the save_file_menu. The function return a 
	/// string from the button pressed. When save-file pressed it returns the 
	/// path to the save-file
	///
	/// \return This function returns a string that is either empty, "BACK" or the path to the save-file pressed.
	///
	std::string display_save_file_menu();
	/// \brief function that is used to start the game
	///
	/// This function is used to start the game. By displaying the start screen and determening 
	/// what level file to use when one is pressed.
	///
	/// \return path to level selected by player
	///
	std::string start_game();

};


