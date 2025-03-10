#include <iostream>
#include <string>

class EntityBase{
    public:
        EntityBase(){
            std::cout << "EntityBase constructor " << std::endl;
        }
        EntityBase(std::string name) : m_name(name){
            std::cout << "EntityBase (name) constructor " << std::endl;
        }
        ~EntityBase(){
            std::cout << "EntityBase destructor " << std::endl;
        }
    private:
        std::string m_name;
};

class Monster : public EntityBase{
    public:
        Monster() : EntityBase("default"){
            std::cout << "Monster constructor " << std::endl;
        }
        ~Monster(){
            std::cout << "Monster destructor " << std::endl;
        }

};


int main(){

    return 0;
}