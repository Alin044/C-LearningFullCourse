#include <iostream>
#include <initializer_list>

struct UDT{
    UDT(){

    }

    ~UDT(){

    }

    private:
        std::initializer_list<int> m_data;
};

int main(){

    return 0;
}