#include <iostream>
#include <string>

#include "rule5.hpp"

IntArray::IntArray(std::string name) : m_name(name), m_data(new int[10]){
    std::cout << m_name << " was constructed " << std::endl;
}

IntArray::~IntArray(){
    std::cout << m_name << " was destructed " << std::endl;
    delete[] m_data;
}

IntArray::IntArray(const IntArray& rhs){
    m_name = rhs.m_name;
    std::cout << " was copy constructed from : " << rhs.m_name << std::endl;
    m_data = new int[10];
    for(int i = 0; i < 10; i++){
        m_data[i] = rhs.m_data[i];
    }
}

//Move constructor
IntArray& IntArray::operator=(const IntArray& rhs){
    
    std::cout << " was constructed from " << rhs.m_name << std::endl;
    if(this != &rhs){
        delete[] m_data;
        m_name = rhs.m_name;
        m_data = new int[10];
        for(int i = 0; i < 10; i++){
            m_data[i] = rhs.m_data[i];
        }
    }
    return *this;
}