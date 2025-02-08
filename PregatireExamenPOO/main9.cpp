#include <iostream>

class Nod{
    int numar;
    Nod *next;

    public:
        void adaugare(Nod* &, int);
        void afisare(Nod*);
        friend void sterg(Nod*, int);
};

Nod *ultim, *nod;

void Nod::adaugare(Nod* &nou, int valoare){
    Nod *temp;

    if(nou == nullptr){
        nou = new Nod;
        nou -> numar = valoare;
        nou -> next = nullptr;
        ultim = nou;
    }else{
        temp = new Nod;
        ultim -> next = temp;
        temp -> numar = valoare;
        temp -> next = nullptr;
        ultim = temp;
    }
}

void Nod::afisare(Nod* c){
    while( c != nullptr){
        std::cout << c -> numar << " ";
        c = c -> next;
    }
    std::cout << std::endl;
}

void sterg(Nod* nod, int valoare){
    Nod* nod1, *nod2;

    if(nod -> numar == valoare){
        nod2 = nod;
        nod = nod -> next;
    }else {
        nod1 = nod;
        while( nod -> next -> numar != valoare){
            nod1 = nod1 -> next;
        }
        nod2 = nod1 -> next;
        nod1 -> next = nod2 -> next;

        if(nod2 == ultim){
            ultim = nod1;
        }
    }
    delete nod2;
}


int main(){

    int i;
    Nod lista;

    for(i = 0; i <= 10; i++){
        lista.adaugare(nod, i);
    }

    lista.afisare(nod);

    sterg(nod, 2);
    lista.afisare(nod);

    return 0;
}