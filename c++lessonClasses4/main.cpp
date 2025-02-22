#include <iostream>
#include <string>
#include "array.hpp"

int main(){

    Array myArray;
    Array myArray2;
    myArray2 = myArray;

    myArray.SetData(0, 100000);
    myArray.SetData(1, 55);
    myArray.SetData(2, 999);

    myArray.PrintingData();
    myArray2.PrintingData();

    // Vector3 myVector;
    // myVector.x = 1.0f;
    // myVector.y = 2.0f;
    // myVector.z = 3.0f;

    // Vector3 myVector2 = myVector;
    // std::cout << myVector.x << " " << myVector.y << " " << myVector.z << std::endl;


    return 0;
}

//The rule of 3
//1. Constructor
//2. Destructor
//3. Copy Constructor (for objects with non raw c++ data types inside)


//==================================

//The Las of the Big Two
//When using a colection, there is no need for a destructor (vector)