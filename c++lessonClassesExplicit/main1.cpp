#include <iostream>
#include <string>

class udt{
    public:
        udt(int);

    private:
        int m_variable;
};

udt::udt(int i){
    m_variable = i;
    
    std::cout << "m_variable : "
              << m_variable 
              << std::endl;
}

int main(){
    udt u1(500);

    return 0;
}

