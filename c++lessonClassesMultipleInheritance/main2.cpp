#include <iostream>


struct Entity{
    int x{4}, y{5};
};

struct Warrior : public Entity{
    int power{10};
};

struct Goblin : public Entity{
    int power{7};
};

struct Player :public Goblin , public Warrion{

};

int main(){
    Player mike;
    std::cout << mike.x << std::endl;
    std::cout << mike.y << std::endl;
    

    return 0;
}