#include <iostream>
#include <string>

// class Vector3{
//     public:
//         float x, y, z;
// };

class Array{
    public:
        Array(){
            data = new int[10];
            for(int i = 0; i < 10; i++){
                data[i] = i * i;
            }
        }
        ~Array(){
            delete[] data;
        }

        void PrintingData(){
            for(int i = 0; i < 10; i++){
                std::cout << data[i] << std::endl;
            }
        }

    private:
        int* data;
};

int main(){

    Array myArray;
    myArray.PrintingData();

    // Vector3 myVector;
    // myVector.x = 1.0f;
    // myVector.y = 2.0f;
    // myVector.z = 3.0f;

    // Vector3 myVector2 = myVector;
    // std::cout << myVector.x << " " << myVector.y << " " << myVector.z << std::endl;


    return 0;
}