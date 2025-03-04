#include <iostream>
//classes inheritance in cpp

class Dog{
    public:
        Dog(){

        }
        void Bark(){
            std::cout << "Bark" << std::endl;
        }
        void Walk(){
            x+= 1;
            y+= 1;
        }

        float x, y;

    private:
};

class Golden : public Dog{
    void Retrieve(){
        
        std::cout << "Retrievering a stick " << std::endl;
        m_sticksReterieved++;
    }

    float m_sticksReterieved;
};

class Husky : public Dog{
    
};

int main(){

    Golden dog1;
    dog1.Bark();
    Husky dog2;
    dog2.Bark();
    Dog dog;
    dog.Bark();

    std::cout << "Sizeof(dog) = " << sizeof(Dog) << std::endl;
    std::cout << "Sizeof(golden) = " << sizeof(Golden) << std::endl;
    std::cout << "Sizeof(husky) = " << sizeof(Husky) << std::endl;


    return 0;
}