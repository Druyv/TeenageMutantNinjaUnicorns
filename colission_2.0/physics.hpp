#ifndef PHYSICS_HPP
#define PHYSICS_HPP

class physics {
public:
        void set_gravity (int value);
        int get_gravity();
        
        float falling();
        float jumping(int counter);
private:
        int gravity_counter = 0;
};

#endif // PHYSICS_HPP
