#include "management.hpp"

file_management::file_management(std::string pathfile, sf::RenderWindow & window,soundtrack & sound):
    window{window},
    sound{sound}
{
    set_input(pathfile);
}

std::string file_management::get_files() {
    std::string safefile;
    input >> safefile;
    return safefile;
}

void file_management::set_input(std::string new_filename) {
    if (input.is_open()) {
        input.close();
    }
    input.open(new_filename);
}

std::string file_management::get_level_file(std::string safe_file) {
    set_input(safe_file);
    std::string file = get_files();
    if (safe_file == save_file_1) {
        current_save_file = 1;
    }
    else if (safe_file == save_file_2) {
        current_save_file = 2;
    }
    for (char c : file) {
        if (c >= '0' && c <= '9') {
            counter = c - 48;
        }
    }	
    if (counter==4){
        cutscene1 scene1(window,sound);
        window.clear();
        scene1.cyan_island();
    }
    return file;
}

std::string file_management::get_save_file(int menu_index) {
    if (menu_index == 1) {
        return save_file_1;
    }
    else if (menu_index == 2) {
        return save_file_2;
    }
    else {
        return "";
    }
}

menu file_management::make_save_file_menu(sf::RenderWindow & window) {
    save_file_1 = get_files();
    save_file_2 = get_files();
    std::cout << "Save-files: " << save_file_1 << " " << save_file_2 << std::endl;
    if (save_file_1 == "") {
        menu(window, std::string{"forest.png"}, true, "BACK");
    }
    else if (save_file_2 == "") {
        return menu(window, std::string{"forest.png"}, true, "SAVE 1", true ,"BACK");
    }
    else {
        return menu(window, std::string{"forest.png"}, true, "SAVE 1", true, "SAVE 2", true, "BACK");
    }
    return menu(window, std::string{"forest.png"}, true, "BACK");
}

std::string file_management::next_level() {
    return std::string(standard_path + "level" + std::to_string(++counter) + ".properties");
}

void file_management::set_counter(int value) {
	counter = value;
}

int & file_management::get_counter(){
    return counter;
}

void file_management::save_game() {
    std::string level_files_1, level_files_2;
    set_input(save_file_1);
    level_files_1 = get_files();
    set_input(save_file_2);
    level_files_2 = get_files();
    if (current_save_file == 1 || (current_save_file == 0 && level_files_1 == "")) {
        output.open(save_file_1);
        counter--;
        output << next_level();
        output.close();
    }
    else if (current_save_file == 2 || (current_save_file == 0 && level_files_2 == "")) {
        output.open(save_file_2);
        counter--;
        output << next_level();
        output.close();
    }
    else {
        output.open(save_file_1);
        counter--;
        output << next_level();
        output.close();
    }
}

//===============================//
//Menu management class functions//
//===============================//

menu_management::menu_management(sf::RenderWindow & window, file_management & manager,soundtrack & sound) :
    window{window},
    manager{manager},
    sound{sound}
{}

int menu_management::display_start_game() {
    window.clear();
    start_menu.build_menu();
    window.display();
    int menu_item_pressed = -1;
    while (menu_item_pressed == -1) {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            menu_item_pressed = start_menu.select(sf::Mouse::getPosition(window));
        }
        if (menu_item_pressed == 3) {
            exit(0);
        }
    }
    window.clear();
    return menu_item_pressed;
}

void menu_management::display_pause_game() {
    window.clear();
    
    //VIEW AANPASSEN
    sf::View playerCam(sf::FloatRect(0, 0, float(window.getSize().x), float(window.getSize().y)));
    playerCam.setCenter(sf::Vector2f{(float)window.getSize().x/2, (float)window.getSize().y/2});
        
    window.setView(playerCam);
    pause_menu.build_menu();
    window.display();
    int menu_item_pressed = -1;
    while (menu_item_pressed == -1) {
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            menu_item_pressed = pause_menu.select(sf::Mouse::getPosition(window));
	}
	if (menu_item_pressed == 2) {
            manager.save_game();
            exit(0);
        }
    }
    window.clear();
}


std::string menu_management::display_save_file_menu() {
    window.clear();
    save_file_menu.build_menu();
    window.display();
    sf::sleep(sf::milliseconds(100));
    int menu_item_pressed = -1;
    while (menu_item_pressed == -1) {;
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            menu_item_pressed = save_file_menu.select(sf::Mouse::getPosition(window));
        }
        if (save_file_menu.get_button_text(menu_item_pressed) != "BACK" && save_file_menu.get_button_text(menu_item_pressed) != "") {
            return save_file_menu.get_button_text(menu_item_pressed);
        }

        if (menu_item_pressed == save_file_menu.last_button()) {
            return "BACK";
        }
    }
    window.clear();
    return "";
}


std::string menu_management::start_game() {
    while (1) {
        if (display_start_game() == 2) {
            sf::sleep(sf::milliseconds(50));
            window.clear();
            std::string safe_file_path = display_save_file_menu();
            while (safe_file_path != "BACK") {
                if (safe_file_path != "") {
                    if (safe_file_path == "SAVE 1") {
                        return manager.get_level_file(manager.get_save_file(1));
                    }
                    else if (safe_file_path == "SAVE 2") {
                        return manager.get_level_file(manager.get_save_file(2));
                    }
                }
		safe_file_path = display_save_file_menu();
            }
            if (safe_file_path == "BACK") {
		sf::sleep(sf::milliseconds(100));
            }	
        }
        else if (display_start_game() == 1) {
            manager.set_counter(0);
            //Story introduction
            window.clear();
            image_from_file story(sf::Vector2f(0,0),"story.png");
            story.set_scale(
                (float)sf::VideoMode::getDesktopMode().width / 1920, 
                (float)sf::VideoMode::getDesktopMode().height / 1080
            );
            story.draw(window);
            window.display();
            while(1){
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
                    break;
                }
            }
            sf::sleep(sf::milliseconds(10));
            window.clear();
            
            cutscene1 scene1(window,sound);
            scene1.play_scene();

            window.clear();
            image_from_file controls(sf::Vector2f(0,0),"controls.png");
            controls.set_scale(
                (float)sf::VideoMode::getDesktopMode().width / 1920, 
                (float)sf::VideoMode::getDesktopMode().height / 1080
            );
            controls.draw(window);
            window.display();
            while(1){
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
                    break;
                }
            }
            sf::sleep(sf::milliseconds(10));
            window.clear();
            return manager.next_level();
        }
    }
    return "";
}
