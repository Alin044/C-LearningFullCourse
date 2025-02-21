#include "Student.hpp"
#include <iostream>
Student::Student(){
    std::cout << "Constructor " << std::endl;
}

Student::~Student(){
    std::cout << "Destructor " << std::endl;
}

void Student::printName(){
    std::cout << "Student name : " << m_name << std::endl;
}