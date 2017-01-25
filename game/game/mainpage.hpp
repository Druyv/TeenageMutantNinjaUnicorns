///@file
/// \mainpage Technical documentation
/// \section unicorn Unicorn
///
/// The unicorn in the game can be created by creating an object of the #unicorn
/// class. The image of the unicorn is created by the #image_from_file class.
/// It also uses the #physics class to create a more realistic jumping and
/// falling motion. The class dus also inherrit #drawable. Drawable comes with
/// his predefined funtions that can be used by the unicorn due to the
/// inherritance. The unicorn class also overrides the couple of abstract
/// functions. These functions are #drawable::draw(), #drawable::move(),
/// #drawable::jump(), #drawable::getGlobalBounds(), #drawable::run_actions(),
/// #drawable::check_for_collisions.  The #unicorn::draw() function first checks if the direction
/// the unicorn is facing is correct. If it is not, the unicorn is turned around.
/// After that either the #physics::jumping() function is called to move the
/// unicorn up or the #physics::falling() function is called to move the unicorn
/// down. There is one exception to both, the unicorn dus not fall if he is on
/// the ground and the unicorn also dus not go up when something is above him.
/// The #unicorn::move() function moves the unicorn right and left unless there
/// is a collision on the side he is trying to move to. The #unicorn::jump()
/// function sets the counter for jumping to 25 so it can be counted down to 3
/// in the draw function. These values seemed to give us the most realistic
/// jumping effect This counter is used to calculate the speed with wich
/// the unicorn goes up in the physics::jumping() function. It dus not do this
/// when he is not on the ground or when the counter is not 0. This way dubble
/// jumping is impossible. #unicorn::getGlobalBounds() returns the global bounds
/// of the image. These global bounds can be used for collision detection. 
/// The #unicorn::run_actions() function goes through the list of actions.
/// It calls the #action::operator()() from the #action class on all the actions
/// and the rest is handled by the operator() function.
///
///
/// \section wall The walls of the game
///
/// The wall creates a rectangle on the screen on specified position and with
/// a specified size. The color of the wall can also be set to an initial color.
/// The class inherrits #drawable to be able to use all its functionality.
/// The functions from drawable that are redefined here are: #drawable::draw(),
/// #drawable::getGlobalBounds(), #drawable::object_information().
/// The #wall::draw() function draws the object and sets the color and position.
/// The #wall::getGlobalBounds() function returns the global bounds of the
/// rectangle. The #wall::object_information() function returns the information 
/// of the object as
/// <a href="http://www.cplusplus.com/reference/string/string/string/">
/// std::string</a>. This includes the size and the color. The rest of the
/// information comes from the #drawable::object_information() function.
///
///
/// \section background the looks of it 
///
/// The background of the game. the background creates a sprite that is covered 
/// troughout the gamefield creating a background for the game. the background is een inheratance of the 
/// #drawable class and uses the #drawable::draw() function for drawing the background.
/// the background class contains a image object where the background is in.
///
///  \section images
/// All the images just in the game are shown as object of the image class.
/// the image class has multiple function that can be used. the image class is a inherintance of the drawable class.
/// image uses also a override of the #drawable::draw(). Furthermore the class contains an #image::set_size() and an #image::set_position()
/// these functions are for setting a new size or position.Finally it contains a function for getting the global bounds called #image::getGlobalBounds() and an #image::setTextureRect()
/// for setting a texture in the image also this function is beeing used for mirroring a image without position change. 
/// 
/// \section drawable
/// 
/// The superclass drawable is the main class for all objects that will be shown on the window.
/// it contains therefor only virtual functions. the #drawable::draw() function is de virtual function for drawing a object on a window,
/// further it contains a #drawable::move(sf::Vector2f delta) function that in default moves the position with delta.
/// For finding out if a drawable object is in collsion with a other drawable object there is a collapse function
/// this function calculates if one of the outherlines are crossing with a outherline of the other drawable if so there is collision found and the 
/// side of collsion will be put in a struct called #collision.
/// For calculating if a outherline is crossing the other outherline  the class contains  the drawable::within() and the drawable::within_range() function these fucntion looks if a certain point is in a given range.
/// furthermore the class contains two functions : #drawable::object_information() and #drawable::string_from_color(), these functions are for returning the information of the object in a <a href="http://www.cplusplus.com/reference/string/string/string/">
/// std::string</a> 
///
/// \section actions
///
///The #action class is a class made for handeling in game actions it contains couple of different constructors that are made for different actions. 
///for using keybaord and mousse there are two different constructors and there is a constructor that can be used in a template way where if parameter 1 gives true 
/// the function given in parameter number 2 will be runt.
///
/// \section physics
///
/// The action class is a class that contains the needed functions for making movement in the game feel natural. 
/// for jumping there is the #physics::jumping() function and for the grafity there is the #physics::falling() function.
///
/// \section  camera
/// the camera class has one thing to do and has also only one function and that is following a object of the #unicorn class
///