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

        void SetData(int index, int value){
            data[index] = value;
        }
        //copy constructor
        //
        Array(const Array& rhs){
            std::cout << "Copy constructor" << std::endl;
            data = new int[10];
            for(int i = 0; i < 10; i++){
                data[i] = rhs.data[i];
            }
        }

        //copy assignment operator
        //object is already constructed
        //makeing a copy later (myArray2 = myArray)
        Array& operator = (const Array& rhs){
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
        

    private:
        int* data;
};

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