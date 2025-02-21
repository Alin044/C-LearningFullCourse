#include <iostream>
#include <string>

class Student{
    public:
        Student(){
            std::cout << "Constructor " << std::endl;
        }

        ~Student(){
            std::cout << "Destructor " << std::endl;
        }
        
        void printName(){
            std::cout << "Student name : " << m_name << std::endl;
        }
    public:
        std::string m_name;
};

int main(){

    Student mike;
    mike.m_name = "Mike";
    mike.printName();

    return 0;
}