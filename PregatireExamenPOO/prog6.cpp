#include <iostream>
#include <string.h>

class Lista;

class ProduseMagazin{
    private:
        int tip_derivat;
        char *producator;
        int cod_produs;
        char *rezolutie;
        char *dimensiuni;
        ProduseMagazin *next;
    public:
        ProduseMagazin(int tip_derivat, char *producator, int cod_produs, char *rezolutie, char *dimensiuni){
            this -> producator = new char[strlen(producator) + 1];
            this -> rezolutie = new char[strlen(rezolutie) + 1];
            this -> dimensiuni = new char[strlen(dimensiuni) + 1];
            strcpy(this->producator, producator);
            strcpy(this->rezolutie, rezolutie);
            strcpy(this->dimensiuni, dimensiuni);
            this -> tip_derivat = tip_derivat;
            this -> cod_produs = cod_produs;
            this -> next = nullptr;
        }

        virtual void afisare(){
            std::cout << "--------------------------------" << std::endl;
            std::cout << "Producator : " << producator << std::endl;
            std::cout << "Cod Produs : " << cod_produs << std::endl;
            std::cout << "Rezolutie : " << rezolutie << std::endl;
            std::cout << "Dimensiuni : " << dimensiuni << std::endl;
        }

        friend class Lista;
};

class Scanere : public ProduseMagazin{
    char *soft_inclus;
    int viteza_scanare;
    public:
        Scanere(int t, char* p, int c, char* r, char* d, char* s, int v):ProduseMagazin(t, p, c, r, d){
            soft_inclus = new char[strlen(s) + 1];
            strcpy(soft_inclus, s);
            viteza_scanare = v;
        }

        void afisare(){
            ProduseMagazin::afisare();
            std::cout << "Soft inclus : " << soft_inclus << std::endl;
            std::cout << "Viteza de scanare : " << viteza_scanare << std::endl;
        }
        friend class Lista;
};

class Imprimante : public ProduseMagazin{
    private:
        char* format;
        char* tip;
    public:
        Imprimante(int t, char* p, int c, char* r, char* d, char* form, char* tp):ProduseMagazin(t, p, c, r, d){
            format = new char[strlen(form) + 1];
            tip = new char[strlen(tp) + 1];
            strcpy(format, form);
            strcpy(tip, tp);
        }

        void afisare(){
            ProduseMagazin::afisare();
            std::cout << "Format : " << format << std::endl;
            std::cout << "Tip : " << tip << std::endl;
        }

        friend class Lista;
};

class Lista{
    public:
        ProduseMagazin* head;
        void adaugare(ProduseMagazin* prod);
        void afisare_lista();
};

void Lista::adaugare(ProduseMagazin* a){
    ProduseMagazin* p;
    p = head;

    if(p != nullptr){
        if(strcmp(a -> producator, p -> producator) < 0){
            a -> next = head;
            head = a;
        }else {
            while(p -> next != nullptr && strcmp((p -> next) -> producator, a -> producator) < 0){
                p = p -> next;
            }
            a -> next = p -> next;
            p -> next = a;
        }
    }else 
        head = a;
}

void Lista::afisare_lista(){
    ProduseMagazin* a;
    a = head;

    if(a == nullptr){
        std::cout << "Lista este vida" << std::endl;
    }else{
        while(a != nullptr){
            a -> afisare();
            a = a -> next;
        }
    }
}

int main(){

    return 0;
}