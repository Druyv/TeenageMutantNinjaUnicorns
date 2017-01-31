/// @file
/// \mainpage Technical documentation
/// \section typedefs The self new types
/// 
/// We have 4 typedefs. Two of them are for the objectes and the other 2 are for
/// sactions and collisions. These typedefs make sure we dont have to repeat the
/// same complicated types over and over again. Also the chance of making a mistake
/// is far less with the more easy names we gave our typedefs. The first typedef
/// is called #object_ptr. This is a std::shared_ptr type to make sure multiple
/// pointers to the same object can exist without any chance of not destructings
/// the actual item propperly. This shared pointer is of type drawable so we can
/// use it with the objects we want on screen. The second typedef is a std::vector
/// with those object_ptrs as type. It is called #objects_vector::B. This is the vector
/// type we put all the objects in so we can loop through them and do what we need to do.
/// We also have a typedef with #collisions. In this typedef we put #collision structs
/// with all the collisions any objects has. The last one is for saving a number of
/// actions for the objects you make. It is called #actions.
/// 
/// \section drawable The drawable superclass
/// 
/// The superclass drawable is the main class for all objects that will be shown on the window.
/// it contains therefor only virtual functions. the #drawable::draw() function is de virtual function for drawing a object on a window,
/// further it contains a #drawable::move(sf::Vector2f delta) function that in default moves the position with delta.
/// For finding out if a drawable object is in collsion with a other drawable object there is a collapse function
/// this function calculates if one of the outherlines are crossing with a outherline of the other drawable if so there is collision found and the 
/// side of collsion will be put in a struct called #collision.
/// For calculating if a outherline is crossing the other outherline  the class contains  the drawable::within() and the drawable::within_range() function these fucntion looks if a certain point is in a given range.
/// furthermore the class contains two functions : #drawable::object_information() and #drawable::string_from_color(), these functions are for returning the information of the object in a <a href="http://www.cplusplus.com/reference/string/string/string/">
/// std::string</a>.
///
/// \section images The images in the game
///
/// All the images just in the game are shown as object of the image class.
/// the image class has multiple function that can be used. the image class is a inherintance of the drawable class.
/// image uses also a override of the #drawable::draw(). Furthermore the class contains an #image::set_size() and an #image_from_file::set_position()
/// these functions are for setting a new size or position.Finally it contains a function for getting the global bounds called #image_from_file::getGlobalBounds() and an #image_from_file::setTextureRect()
/// for setting a texture in the image also this function is beeing used for mirroring a image without position change. 
/// 
///
/// \section unicorn Unicorn
///
/// The unicorn and it's rainbow in the game acan be created by creating an object of the #unicorn
/// class. Rainbow get's it's location by using the location of the unicorn in combination with 
/// the location of the window. The image of the unicorn and of the rainbow are created by
/// the #image_from_file class. the unicorn also uses the #physics class to create a more 
/// realistic jumping and falling motion. The class dus also inherrit #drawable. Drawable comes with
/// his predefined funtions that can be used by the unicorn due to the
/// inherritance. The unicorn class also overrides the couple of abstract
/// functions. These functions are #drawable::draw(), #drawable::move(),
/// #drawable::jump(), #drawable::getGlobalBounds(), #drawable::run_actions(),
/// #drawable::check_for_collisions. The #unicorn::draw() function first checks if the direction
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
/// \section actions The actions for the different objects
///
///The #action class is a class made for handeling in game actions it contains couple of different constructors that are made for different actions. 
///for using keybaord and mousse there are two different constructors and there is a constructor that can be used in a template way where if parameter 1 gives true 
/// the function given in parameter number 2 will be runt.
///
/// \section animation the animation in the game 
/// 
/// the animation class is the class that makes the objects in the game have animations like 
/// walking around and loop when jumping the way the animations work is a big picture with multiple states on it in which the program will loop in and making the walk movement or other movement in which  the sheet is set. One sheet contains multiple rows with multiple lines 
///each line is one animation and some animations are made bij using <a href="https://www.sfml-dev.org/documentation/2.0/classsf_1_1Sprite.php">sf::sprite</a>  functions like<a href="https://www.sfml-dev.org/documentation/2.0/classsf_1_1Transformable.php#a32baf2bf1a74699b03bf8c95030a38ed">sf::sprite::setRotation</a> and<a  href="https://www.sfml-dev.org/documentation/2.0/classsf_1_1Transformable.php#aa93a835ffbf3bee2098dfbbc695a7f05">sf::sprite::setOrigin</a> for the jump.
///By resetting the origin to position 0.5*size  the rotation will be in the middle of the certain object.
///And after that replacing the origin to the position which makes it turn around the mid without teleport like bugs. 
///
/// \section physics The game's physics
///
/// The action class is a class that contains the needed functions for making movement in the game feel natural. 
/// for jumping there is the #physics::jumping() function and for the grafity there is the #physics::falling() function.
///
/// \section background The background of the game 
///
/// The background of the game. the background creates a sprite that is covered 
/// troughout the gamefield creating a background for the game. the background is een inheratance of the 
/// #drawable class and uses the #drawable::draw() function for drawing the background.
/// the background class contains a image object where the background is in.
///
/// \section  camera The player folowing camera
///
/// The camera class has one thing to do and has also only one function and that is following a object of the #unicorn class.
///
/// \section sound The sound in the games
/// the soundtrack class is the class that handles the background music in this class is set the sound file by
/// setting the music in the constructor and playing it by the playmusic function. 
///
///
/// \section base_level The level boundary's
///
/// Every level gets level boundary's. These boundary's are based on the level size read
/// by the #factory from the level files. These boundary's are made transparent. They are
/// also created with a offset to make sure the borders are not in the upper left corner
/// of the background. This way you do not see a partially black background. These level
/// boundary's can be put into a objects vector by calling the #base_level::push_back_borders()
/// function from the class and giving it the vector you want to put them in as parameter.
///
/// \section factory Reading files with the factory
///
/// The factory can be used to read out level files. An example of a level file is the following:
///
/// SPAWN (1030,1500).\n
/// LEVEL_SIZE (4000,3350).\n
/// WALL (1020.000000,2000.000000) (100.000000,20.000000) green grass.png.\n
/// WALL (1499.824341,2133.414062) (100.000000,20.000000) green grass.png
///
/// The first two lines are always neccesary because the level wil not have a correct size
/// or a spawn point without them. The rest can be customized to what level you want. In
/// The factory there are 6 functions. The first one is called #factory::change_input_to()
/// and is used to change the input file. If a file is already open it closes that file first.
/// The second and third are used to read lines from the input file. They are called #factory::
/// read_line() and #factory::objects_from_file(). The read line function reads a single line and
/// returnes an #object_ptr to the newly created object or an error of different types if something
/// went wrong. The objects from file function handles all the errors and puts the objects in an 
/// #objects_vector. This vector is returned. The next function is called
/// #factory::write_information_to_file() and writes all the information about
/// objects to a file. This repeatedly calles the #drawable::object_information() function
/// after the spawn and level size ar already put into the file. The last two functions are
/// for getting the level size and the spawn location from the factory. The names for these
/// functions are #factory::get_spawn() and #factory::get_level_size().
/// 
/// \section bullet Shooting feature
///
/// The bullet class is used to move a #image_from_file object (in this game Nyan-Cat.png) a amount of spots.
/// When the bullet animation collides (this is checked with #bullet::collision()) with either 
/// a wall or a mob the bullet is reset and not drawn until it is fired agian. With #unicorn::shoot()
/// the bullet is activated. 
///
/// \section mob Enemy creatures 
/// 
/// The mob class is used to display an enemy. When #mob::mob() is called the mob is always alive. When #mob::die() is 
/// called the mob dies and the variable alive is set to false , this means it isn't drawn anymore and has a empty global bounds
/// . The global bounds is empty to make sure the bullet goes through the mob when it has died. #mob::revive() can be used to set the 
/// variable alive to true 
///
/// \section menu The menu's 
///
///  The main menu consists mainly of 2 parts. First , the background image. This is an object of the 
///  #Background class. This sets the background sprite with the specified image. Second, the buttons 
///  that make up the menu. The main menu consists of three buttons, these are #Button objects. 
///  Together they make up the visual aspect of the menu. The clickable part is handled in  menu::Select(), 
///  where the collision detection  <a href="https://www.sfml-dev.org/documentation/2.0/classsf_1_1Rect.php#aa8a5364c84de6dd5299f833b54e31ef1 ">standard SFML Rect::contains()</a>   triggers if the button 
///  is clicked with the cursor ( left mouse button ). 
///
///  \section Button The buttons 
///
///  The buttons are made specifically tailored for our game. The buttons are all customizable,
///  background is easy  to change as is the font. 
/// 
///  All the math in this class is done to make sure the buttons are aligned 
///  in the middle of the screen, regardless of resolution. However, SFML does not have a native 
///  rescale of pictures in sprites. Which means that the background of the buttons will be completely distorted 
///  in some resolutions. Also, a lot of this math could be moved to the #menu class, 
///  which would make the #Button class more re-useable. 

