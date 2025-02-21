#ifndef STUDENT_HPP
#define STUDENT_HPP
#include <string>

class Student{
    public:
        Student();

        ~Student();
        
        void printName();
    public:
        std::string m_name;
};

#endif