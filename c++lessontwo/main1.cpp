#include <iostream>
#include <memory>

//raw pointers allow sharing, but they allow room for errors, forgeting to dealocate, ownership
//introduction to smart pointers 
//smart pointers address these issues, no need to dealocate memory
//https://www.youtube.com/watch?v=DHu0tv2qTYo&list=PLvv0ScY6vfd8j-tlhYVPYgiIyXduu6m-L&index=34

class UDT{
    public:
        UDT(){ std::cout << "UDT created" << std::endl;}
        ~UDT(){ std::cout << "UDT destroyed" << std::endl;}
};

int main(){
    
    std::unique_ptr<UDT> mike = std::unique_ptr<UDT>(new UDT);

    return 0;
}