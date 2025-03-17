#include <iostream>
#include <initializer_list>

struct UDT{

    UDT(int a, int b, int c){
        std::cout << "UDT constructor" << std::endl;
        
    }

    UDT(std::initializer_list<int> data) : m_data(data){
        std::cout << "Initializer list constructor " << std::endl;
       // m_data = data;
    }

    ~UDT(){

    }
    void printData(){
        for(auto& e : m_data){
            std::cout << e << std::endl;
        }
    }

    private:
        std::initializer_list<int> m_data;
};

int main(){

    UDT u{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    u.printData();

    return 0;
}