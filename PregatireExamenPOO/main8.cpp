#include <iostream>

class A{
    private : 
        int m;
    public :
        friend class B;
        friend void g_afiseaza_m();
};

class B{
    public : 
        void afiseaza_m(){
            A a;
            a.m = 255;
            std::cout << "clasa B este prietena cu clasa A " << std::endl
                      << " poate accesa membrul privat A::m " << std::endl << a.m << std::endl;
        }
};

void g_afiseaza_m(){
    A a;
    a.m = 300;
    std::cout << "functia g_afiseaza_m nu este un membru a clasei A dar este prieten " << std::endl << a.m << std::endl;
}

int main(){
    B b;

    b.afiseaza_m();
    g_afiseaza_m();

    return 0;
}