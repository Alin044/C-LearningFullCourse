#include <iostream>

class Base{
    public:
        Base(){
            std::cout << "Base constructor" << std::endl;
        }
        ~Base(){
            std::cout << "Base destructor" << std::endl;
        }

    public:
        int m_base_public_member_variable;
    protected:
        int m_base_protected_member_variable;
    private:
        int m_base_private_memeber_variable;
};

class Derived : protected Base{
    public:
        Derived(){
            std::cout << "Derived constructor" << std::endl;
            m_base_public_member_variable = 123;
    //ERROR m_base_protected_member_variable = 123;
    //ERROR m_base_private_member_variable = 123;
        }
        ~Derived(){
            std::cout << "Derived destructor" << std::endl;
        }
};

int main(){

    Derived d;
    //d.m_base_public_member_variable = 100;
//ERROR d.m_base_protected_member_variable = 100;
//ERROR d.m_base_private_member_variable = 100;

    return 0;
}