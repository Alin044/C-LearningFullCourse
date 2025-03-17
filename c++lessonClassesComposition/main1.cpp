#include <iostream>

struct Point2D{
    int x, y;
};

class Character{
    public:
        Character(Point2D ref) : ref_home(ref){
            //ref_home = ref;
        }
        ~Character(){}

    private:
        Point2D m_position;
        Point2D m_direction;
        Point2D ref_home;
};

Point2D somePoint;

int main(){

//    Point2D somePoint;
    Character mike(somePoint);

    return 0;
}
//The point2D and Character are not tied together so they might have different lifetimes