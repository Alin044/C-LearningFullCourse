#include <iostream>

class Dreptunghi{
    int latime, lungime;
    public:
        Dreptunghi(int, int);

        int calc_arie(){
            return latime * lungime;
        }
};

Dreptunghi::Dreptunghi(int l, int L){
    latime = l;
    lungime = L;   
}

int main(){

    Dreptunghi DreptA(3, 5);
    Dreptunghi DreptB(6, 9);
    std::cout << "Arie dreptunghi A : " << DreptA.calc_arie() << std::endl;
    std::cout << "Arie dreptunghi B : " << DreptB.calc_arie() << std::endl;

    return 0;
}