#include <iostream>
#include "array.hpp"

        //special member functions
        //1. constructor
        Array::Array(){
            std::cout << "Constructor" << std::endl;
            for(int i = 0; i < 100000; i++){
                data.push_back(i);
            }
        }

        Array::~Array(){
            
        }
        void Array::PrintingData(){
            for(int i = 0; i < data.size(); i++){
                std::cout << data[i] << std::endl;
            }
        }

        void Array::SetData(int index, int value){
            data[index] = value;
        }
        //copy constructor
        //
        Array::Array(const Array& rhs){
            std::cout << "Copy constructor" << std::endl;
            for(int i = 0; i < rhs.data.size(); i++){
                data.push_back(rhs.data[i]);
            }
        }

        //copy assignment operator
        //object is already constructed
        //makeing a copy later (myArray2 = myArray)
        Array& Array::operator = (const Array& rhs){
            std::cout << "Copy assignment operator" << std::endl;
            if(&rhs == this){
                return *this; 
            }
            for(int i = 0; i < rhs.data.size(); i++){
                data.push_back(rhs.data[i]);
            }        
            return *this;
        }