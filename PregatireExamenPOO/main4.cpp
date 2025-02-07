#include <iostream>
#include <cstring>

class Carte{
    char titlu[64];
    float const cost2 = 100;
    protected:
        void afis_cost2(){
            std::cout << "Costul 2 : " << cost2 << std::endl;
        }
    public:
        Carte(char* titlu){
            strcpy(Carte::titlu, titlu);
            std::cout << "Constructorul classei Carte" << std::endl;
        }
        void afisareCarte(){
            std::cout << "Titlu : " << titlu << std::endl;
        }
        ~Carte(){
            std::cout << "Destructorul clasei carte " << std::endl;
        }
    protected:
        float cost;
        void afisareCost(){
            std::cout << "Cartea costa : " << cost << std::endl;
        }
};

class Pagini {
    protected:
        int linii;

    public:
        Pagini(int linii){
            Pagini::linii = linii;
            std::cout << "Constructorul clasei Pagini " << std::endl;
        }
        
        void afisarePagini(){
            std::cout << "Cartea are nr de pagini : " << linii << std::endl;
        }
};

class FisaBiblioteca:Carte, Pagini{
    char autor[64], editura[64];
    public:
        FisaBiblioteca(char* titlu, const char* autor,char* editura):Carte(titlu),Pagini(50)
        {
            strcpy(FisaBiblioteca::autor, autor);
            strcpy(FisaBiblioteca::editura, editura);
            cost = 100;
            std::cout << "Constructorul clasei FisaBiblioteca " << std::endl;
        }
        void afisareBiblio(){
            afisareCarte();
            afisareCost();
            afis_cost2();
            std::cout << " Autor : " << autor << std::endl << "Editura : " << editura << std::endl;
            afisarePagini();
        }
};

int main(){
    FisaBiblioteca fisa("Programare orientata pe Obiect", "Vasile Stoicu", "Politehnica");
    fisa.afisareBiblio();
    return 0;
}