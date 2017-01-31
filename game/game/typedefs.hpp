#ifndef TYPEDEFS_HPP
#define TYPEDEFS_HPP

class drawable;
class action;
class mob;
struct collision;

///std::shared_ptr to a #drawable object
typedef std::shared_ptr<drawable> object_ptr;

///std::vector with #object_ptr objects
typedef std::vector<object_ptr> objects_vector;

///std::vector with #collision objects
typedef std::vector<collision> collisions;

///std::vector with #action objects
typedef std::vector<action> actions;

///std::shared_ptr with #mob objects
typedef std::shared_ptr<mob> mob_ptr;


#endif // TYPEDEFS_HPP
