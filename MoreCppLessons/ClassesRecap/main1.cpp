#include <iostream>
#include <string>

struct Entity{

    public:
        // Entity(): x(0), y(0), collection(nullptr), name("Mike"){
            // x = 0;
            // y = 0;
            // collection = nullptr;
        // }

        // Entity() = default;

        Entity() : name{}, x{0}, y{0}, collection{nullptr} {
            name = std::to_string(x) + std::to_string(y);
            
            //Compute some algorithm
            //Add our entity to some data structure
            init();
        }


        Entity(std::string _name): Entity(){
            //Compute some algorithm
            //Add our entity to some data structure
            init();
        }

        Entity(int x, int y) : Entity(){
            //Compute some algorithm
            //Add our entity to some data structure
            init();
            this->x = x;
            this->y = y;
        }
    private:

        void init(){
            name = std::to_string(x) + std::to_string(y);
        }

        std::string name;
        int* collection;
        int x;
        int y; 
};

int main(){

    Entity entity{9, 27};
    // std::cout << entity.name << std::endl;
    // std::cout << entity.x << std::endl;
    // std::cout << entity.y << std::endl;
    // std::cout << entity.collection << std::endl;

    return 0;
}