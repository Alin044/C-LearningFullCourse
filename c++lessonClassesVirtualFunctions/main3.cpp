#include <iostream>
//vtable pointer


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
    //Create a Base* that can poin to 'Base' or 'Derived', i.e. antything 
    //that 'is-a'.
    //We also have a vtable that is created for this instance of the object 
    Base* instance = new Derived();
    //When we call a member function, the vtable points us to the correct member function
    instance -> Base :: MemberFunc();

    delete instance;
    instance = new Base;
    instance -> MemberFunc();

    delete instance;
    Derived d;


    return 0;
}