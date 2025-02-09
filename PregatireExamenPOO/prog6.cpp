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

class Supraincarcare{
    public:
        char producator[80];
        int cod_produs;
        char rezolutie[100];
        char dimensiuni[100];
    public:
        friend std::ostream& operator<<(std::ostream& out, Supraincarcare &a);
        friend std::istream& operator<<(std::istream& in,  Supraincarcare &a);
};

std::ostream& operator<<(std::ostream& out, Supraincarcare &a){
    std::cout << "Vom citi datele pentru scanere si imprimante: " << std::endl;
    std::cout << std::endl;
    return out;
}

std::istream& operator>>(std::istream& in, Supraincarcare &a){
    std::cout << "Introduceti Producatorul : ";
    std::cin  >> a.producator;
    std::cout << "Introduceti codul produsului : ";
    std::cin  >> a.cod_produs;
    std::cout << "Introduceti rezolutia : ";
    std::cin  >> a.rezolutie;
    std::cout << "Introduceti dimensiunile : ";
    std::cin  >> a.dimensiuni;
    return in;
}

void insert(Lista &l, int x){
    int Tip_derivat;
    char Soft_inclus[100];
    int Viteza_scanare;
    char Format[20];
    char Tip[20];
    ProduseMagazin* prodMag;

    Supraincarcare supr;

    std::cout << supr;
    std::cin >> supr;

    if(x == 0){
        Scanere *Sc;
        std::cout << "Introduceti Softul : ";
        std::cin  >> Soft_inclus;
        std::cout << "Introduceti viteza de scanare : ";
        std::cin  >> Viteza_scanare;

        Sc = new Scanere(1, supr.producator, supr.cod_produs, supr.rezolutie, supr.dimensiuni, Soft_inclus, Viteza_scanare);
        prodMag = Sc;
        l.adaugare(prodMag);
    }else if(x == 1){
        Imprimante *Im;
        std::cout << "Introduceti formatul : ";
        std::cin  >> Format;
        std::cout << "Introduceti tipul : ";
        std::cin  >> Tip;

        Im = new Imprimante(2, supr.producator, supr.cod_produs, supr.rezolutie, supr.dimensiuni, Format, Tip);
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
        std::cout << "1. Adaugare scanere in Lista. " << std::endl;
        std::cout << "2. Adaugare imprimante in Lista. " << std::endl;
        std::cout << "3. Afisare articole din magazin. " << std::endl;
        std::cout << "0. Iesire. " << std::endl;
        std::cout << "Selectati optiunea dorita : " ;
        std::cin  >> opt;

        switch(opt){
            case 1:
                insert(l, 0);
                break;
            case 2:
                insert(l, 1);
                break;
            case 3:
                l.afisare_lista();
                break;
            case 0:
                //exit case 
            default:
                std::cout << "Unavailable option " << std::endl;
                break;
        }
    }while(opt != 0);

    return 0;
}