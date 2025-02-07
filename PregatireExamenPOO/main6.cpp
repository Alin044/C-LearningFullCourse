#include <iostream>
#include <cstring>

class Carte{
    char* titlu;
    public:
        Carte(char* titlu){
            this->titlu = new char[strlen(titlu) + 1];
            strcpy(this->titlu, titlu);
        }

        void displayCarte(){
            std::cout << "Titlu : " << titlu << std::endl;
        }
    protected:
        float cost;
        void displayCost(){
            std::cout << "Cost : " << cost << std::endl;
        }
};

class FisaBiblioteca:public Carte{
    char autor[64];
    char editura[64];
    public:
        FisaBiblioteca(char* titlu, char* autor, char* editura):Carte(titlu){
            strcpy(this->autor, autor);
            strcpy(this->editura, editura);
            cost = 100;
            std::cout << "Constructorul clasei FisaBiblioteca " << std::endl;
        }
        void displayBiblioteca(){
            displayCarte();
            displayCost();
            std::cout << "Autor : " << autor << std::endl << "Editura : " << editura << std::endl;
        }
};


int main(){


    return 0;
}