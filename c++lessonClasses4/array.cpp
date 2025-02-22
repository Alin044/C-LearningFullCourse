#include <iostream>
#include "array.hpp"

        //special member functions
        //1. constructor
        Array::Array(){
            data = new int[10];
            for(int i = 0; i < 10; i++){
                data[i] = i * i;
            }
        }
        //destructor
        Array::~Array(){
            delete[] data;
        }

        void Array::PrintingData(){
            for(int i = 0; i < 10; i++){
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
            data = new int[10];
            for(int i = 0; i < 10; i++){
                data[i] = rhs.data[i];
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
            delete[] data;
            data = new int[10];
            for(int i = 0; i < 10; i++){
                data[i] = rhs.data[i];
            }        
            return *this;
        }