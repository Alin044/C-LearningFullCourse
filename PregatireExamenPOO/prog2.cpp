#include <iostream>

class Forma{
    public:
        virtual void afisareNumeForma(){
            std::cout << "Forma -> clasa de baza" << std::endl;
        }
};

class Punct : public Forma{
    public:
        void afisareNumeForma(){
            std::cout << "Punct -> clasa derivata Punct" << std::endl;
        }
};


int main(){
    std::cout << "Functii apelate prin pointer la forma initializat prin pointer la Punct " << std::endl;
    Forma* ptrForma = new Forma();
    ptrForma -> afisareNumeForma();

    Punct* ptrPunct = new Punct();
    ptrForma = ptrPunct;
    std::cout << "Comportament polimorfic " << std::endl;
    ptrForma -> afisareNumeForma();

    std::cout << "Functii apelate prin obiect de tip forma " << std::endl;
    Forma forma;
    forma.afisareNumeForma();

    std::cout << "Functii apelate prin obiect de tip punct " << std::endl;
    Punct punct;
    punct.afisareNumeForma();

    return 0;
}