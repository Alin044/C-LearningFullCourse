#include <iostream>
#include <string.h>
#include <string>

class Lista;

class ProduseMagazin{
    private:
        int tip_derivat;
        std::string producator;
        int cod_produs;
        ProduseMagazin* next;
    public:
        ProduseMagazin(int tip_derivat, std::string producator, int cod_produs){
            this->tip_derivat = tip_derivat;
            this->producator = producator;
            this->cod_produs = cod_produs;
            next = nullptr;
        }

        virtual void afisare(){
            std::cout << "-----------------------------------" << std::endl;
            std::cout << "Producator : " << producator << std::endl;
            std::cout << "Cod Produs : " << cod_produs << std::endl;
        }

        friend class Lista;
};

class Scanere : public ProduseMagazin{
    private:
        std::string soft_inclus;
    public:
        Scanere(int t, std::string prod, int cod, std::string soft):ProduseMagazin(t, prod, cod){
            soft_inclus = soft;
        }

        void afisare(){
            ProduseMagazin::afisare();
            std::cout << "Soft Inclus : " << soft_inclus << std::endl;
        }
        friend class Lista;
};

class Imprimante : public ProduseMagazin{
    private:
        std::string format;
    public:
        Imprimante(int t, std::string prod, int cod, std::string form):ProduseMagazin(t, prod, cod){
            format = form;
        }

        void afisare(){
            ProduseMagazin::afisare();
            std::cout << "Format : " << format << std::endl;
        }

        friend class Lista;
};

class Lista{
    public:
        ProduseMagazin* head;
        void adaugare(ProduseMagazin* prod);
        void afisareLista();
};

void Lista::adaugare(ProduseMagazin* a){
    ProduseMagazin* p;

    p = head;
    if(p != nullptr){
        if(a -> producator == p -> producator){
            a -> next = head;
            head = a;
        }else {
            while(p -> next != nullptr && (p -> next)-> producator == a -> producator){
                p = p -> next;
            }
            a -> next = p -> next;
            p -> next = a;
        }
    }else 
        head = a;
}

void Lista::afisareLista(){
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

void insert(Lista& l, int x){
    int Tip_derivat;
    std::string Producator;
    int Cod_produs;
    std::string Soft_inclus;
    std::string Format;
    ProduseMagazin* prodMag;

    std::cout << "Introduceti Producatorul : " ;
    std::cin  >> Producator;
    std::cout << "Introduceti codul de produs : ";
    std::cin  >> Cod_produs;

    if(x == 0){
        Scanere *Sc;
        std::cout << "Introduceti softul inclus";
        std::cin  >> Soft_inclus;
        std::cout << "Introduceti viteza de scanare";

        Sc = new Scanere(1, Producator, Cod_produs, Soft_inclus);
        prodMag = Sc;
        l.adaugare(prodMag);
    }else if(x == 1){
        Imprimante *Im;
        std::cout << "Introduceti formatul Imprimantei : " ;
        std::cin  >> Format;

        Im = new Imprimante(2, Producator, Cod_produs, Format);
        prodMag = Im;
        l.adaugare(prodMag);
    }
}

int main(){
    int opt;
    Lista l;
    l.head = nullptr;
    do{
        system("CLS");
        std::cout << "1. Adaugare scanere in lista, ordonat dupa producator." << std::endl;
        std::cout << "2. Adaugare imprimante in lista, ordonat dupa producator. " << std::endl;
        std::cout << "3. Afisare articole din magazin. " << std::endl;
        std::cout << "0. Iesire" << std::endl;
        std::cout << "Selectati optiunea voastra : ";
        std::cin  >> opt;

        switch(opt){
            case 1: 
                insert(l, 0);
                break;
            case 2:
                insert(l, 1);
                break;
            case 3:
                l.afisareLista();
                break;
            case 0: break;
            default: std::cout << "Ati ales o optiune invalida " << std::endl;
        }
    }while(opt != 0);

    return 0;
}