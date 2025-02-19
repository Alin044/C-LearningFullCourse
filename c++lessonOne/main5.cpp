#include <iostream>
#include <string>


int main(){
    
    std::string myString = "copy construct my";
    std::string newValue;

    std::cout << "My string : " << myString << std::endl;
    std::cout << "New Value : " << newValue << std::endl;

    newValue = std::move(myString);

    std::cout << "My string : " << myString << std::endl;
    std::cout << "New Value : " << newValue << std::endl;   

    return 0;
}