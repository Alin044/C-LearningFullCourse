#include <iostream>
#include <string>
//Operator Overloading 

class Vector3f{
    public:
        float x, y, z;

        Vector3f(){
            x = 0.0f;
            y = 0.0f;
            z = 0.0f;
        }
        Vector3f operator+(const Vector3f& rhs){
            Vector3f result;
            result.x = x + rhs.x;
            result.y = y + rhs.y;
            result.z = z + rhs.z;
            return result;
        }

        Vector3f operator++(){
            x = x + 1;
            y = y + 1;
            z = z + 1;
            return *this;
        }
        bool operator==(const Vector3f& rhs){
            if(x == rhs.x && y == rhs.y && z == rhs.z){
                return true;
            }
            return false;
        }
};

std::ostream& operator<<(std::ostream& os, const Vector3f& obj){
    os << obj.x << std::endl << obj.y << std::endl << obj.z << std::endl;
    return os;
}

// bool operator==(const Vector3f& lhs, const Vector3f& rhs){
//     if(lhs.x == rhs.x && lhs.y == rhs.y && lhs.z == rhs.z){
//         return true;
//     }
//     return false;
// }

int main(){

    Vector3f myVector;
        myVector.x = 1.0f;
        myVector.y = 2.0f;
        myVector.z = 3.0f;
    Vector3f myVector2;
        myVector2.x = 3.0f;
        myVector2.y = 2.0f;
        myVector2.z = 1.0f;

    if(myVector == myVector2){
        std::cout << "The vectors are equal!" << std::endl;
    }else {
        std::cout << "The vectors are not equal!" << std::endl;
    }

    Vector3f result;
    result = myVector + myVector2;
    myVector = myVector + myVector2;
    std::cout << result.x << std::endl << result.y << std::endl << result.z << std::endl;
    ++myVector;
    ++myVector;
    ++myVector;
    std::cout << myVector.x << std::endl << myVector.y << std::endl << myVector.z << std::endl;
    std::cout << myVector;



    return 0;
}