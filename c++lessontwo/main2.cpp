#include <iostream>
#include <memory>

class UDL{
    public:
        UDL(){std::cout << "UDL created" << std::endl;}
        ~UDL(){ std::cout << "UDL destroyed" << std::endl;}
};

//https://www.youtube.com/watch?v=1RtiiRpjq6w&list=PLvv0ScY6vfd8j-tlhYVPYgiIyXduu6m-L&index=34
//the shared pointer helps us avoid calling new and delete

int main(){

    std::shared_ptr<UDL> ptr1 = std::make_shared<UDL>();
    std::shared_ptr<UDL> ptr1 = ptr1;

    std::cout << "Use count = " << ptr1.use_count() << std::endl;
 
    return 0;
}