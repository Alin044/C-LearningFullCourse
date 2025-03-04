#include <iostream>
#include <string>

class udt{
    public:
        explicit udt(int);

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
    udt u1{500};
    //udt u2 = 500 in cazul in care nu folosim explicit 
    //does not allow me to give a different data type than what the constructor asks for 

    return 0;
}

