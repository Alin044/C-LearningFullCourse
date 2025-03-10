#include <iostream>

class Base{
    public:
        Base(){
            std::cout << "Base constructor" << std::endl;
        }
        ~Base(){
            std::cout << "Base destructor" << std::endl;
        }

        virtual void MemberFunc(){
            std::cout << "Base::MemberFunc()" << std::endl;
        }
};

class Derived : public Base{
    public:
        Derived(){
            std::cout << "Derived constructor" << std::endl;
        }
        ~Derived(){
            std::cout << "Derived destructor" << std::endl;
        }

        void MemberFunc() override{
            std::cout << "Derived::MemberFunc()" << std::endl;
        }
};

int main(){

    Base* instance = new Derived();
    instance -> Base :: MemberFunc();

    delete instance;

    return 0;
}