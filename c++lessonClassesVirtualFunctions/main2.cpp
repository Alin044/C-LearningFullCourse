#include <iostream>

class Base{
    public:
        Base(){
            std::cout << "Base constructor" << std::endl;
            baseData = new int[10];
        }
        virtual ~Base(){
            std::cout << "Base destructor" << std::endl;
            delete[] baseData;
        }

        virtual void MemberFunc(){
            std::cout << "Base::MemberFunc()" << std::endl;
        }

    int* baseData;
};

class Derived : public Base{
    public:
        Derived(){
            std::cout << "Derived constructor" << std::endl;
            derivedData = new int[15];
        }
        ~Derived(){
            std::cout << "Derived destructor" << std::endl;
            delete[] derivedData;
        }

        void MemberFunc() override{
            std::cout << "Derived::MemberFunc()" << std::endl;
        }
    int* derivedData;
};

int main(){

    Base* instance = new Derived();
    instance -> Base :: MemberFunc();

    delete instance;

    Derived d;


    return 0;
}