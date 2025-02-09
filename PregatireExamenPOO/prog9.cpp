#include <iostream>
#include <string.h>

class Lista;

class agentie{
    private:
        int tip;
        char* nume;
        int pret;
        int tenis;
        agentie* next;
    public:
        agentie(int tip, char* nume, int pret, int tenis){
            this -> tip = tip;
            this -> nume = new char[strlen(nume) + 1];
            strcpy(this -> nume, nume);
            this -> pret = pret;
            this -> tenis = tenis;
            next = nullptr;
        }

        virtual void afisare(){

            std::cout << "-------------------------------" << std::endl;
            std::cout << "Nume : " << nume << std::endl;
            std::cout << "Pret : " << pret << std::endl;
            std::cout << "Tenis : " << tenis << std::endl;
        }

        friend class Lista;
};

class hotel : public agentie{
    private:
        int nr_stele;
        int piscina;
        int sauna;
    public:
        hotel(int tip, char* nume, int pret, int tenis, int nr, int pis, int sau) : agentie(tip, nume, pret, tenis){
            nr_stele = nr;
            piscina = pis;
            sauna = sau;
        }

        void afisare(){
            agentie::afisare();
            std::cout << "Numar stele : " << nr_stele << std::endl;
            std::cout << "Piscine : " << piscina << std::endl;
            std::cout << "Sauna : " << sauna << std::endl;
        }
        friend class Lista;
};

class pensiune : public agentie{
    private:
        int nr_margarete;
        int gradina;
    public:
        pensiune(int tip, char* nume, int pret, int tenis, int nr, int gr) : agentie(tip, nume, pret, tenis){
            nr_margarete = nr;
            gradina = gr;
        }

        void afisare(){
            agentie::afisare();
            std::cout << "Numar de margarete : " << nr_margarete << std::endl;
            std::cout << "Gradina : " << gradina << std::endl;
        }

        friend class Lista;
};

class Lista{
    public:
        agentie* head;
        void adaugare(agentie* a);
        void afisare_lista();
};

class MyException{
    public:
        char str_what[80];
        int what;
        MyException(){
            *str_what = 0;
            what = 0;
        }

        MyException(const char *s, int e){
            strcpy(str_what, s);
            what = e;
        }
};

void Lista::adaugare(agentie* a){
    agentie *p;
    p = head;

    if(p != nullptr){
        if(strcmp(a -> nume, p -> nume) < 0){
            a -> next = head;
            head = a;
        } else {
            while(p -> next != nullptr && strcmp((p -> next) -> nume, a-> nume) < 0)
                p = p -> next;
            
            a -> next = p -> next;
            p -> next = a;
        }
    }else{
        head = a;
    }
}

void Lista::afisare_lista(){

    agentie* a;
    a = head;

    if(a == nullptr){
        std::cout << "Lista este vida" << std::endl;
    }else {
        while( a != nullptr){
            a -> afisare();
            a = a -> next;
        }
    }
}

void introducere(Lista& l, int x){
    char nume[20];
    int pret;
    int tenis;
    int nr_stele;
    int piscina;
    int sauna;
    int nr_margarete;
    int gradina;
    agentie* a;

    std::cout << "Dati numele : " ;
    std::cin  >> nume;
    
    try{
        std::cout << "Dati pretul camerei : " ;
        std::cin  >> pret;
        if(pret < 0)
            throw MyException("Pretul nu este pozitiv", pret);
    }
    catch(MyException e){
        std::cout << e.str_what << " : ";
        std::cout << e.what << std::endl;
    }

    std::cout << "Introduceti daca are teren de tenis[0/1] : ";
    std::cin  >> tenis;

    if(x == 0){
        hotel *h;
        std::cout << "Introduceti numarul de stele : ";
        std::cin  >> nr_stele;
        std::cout << "Introduceti daca are piscina[0/1] : ";
        std::cin  >> piscina;
        std::cout << "Introduceti daca are sauna [0/1] : ";
        std::cin  >> sauna;

        h = new hotel(1, nume, pret, tenis, nr_stele, piscina, sauna);
        a = h;
        l.adaugare(a);
    } else if(x == 1){
        pensiune *p;
        std::cout << "Introduceti numarul de margarete : ";
        std::cin  >> nr_margarete;
        std::cout << "Introduceti daca are gradina numarul : ";
        std::cin  >> gradina;
        p = new pensiune(2, nume, pret, tenis, nr_margarete, gradina);
        a = p;
        l.adaugare(a);
    }
}


int main(){

    int opt;
    Lista l;
    l.head = nullptr;

    do{
        system("cls");
        std::cout << "1. Adaugare oferte hotel : " << std::endl;
        std::cout << "2. Daugare oferte pensiune : " << std::endl;
        std::cout << "3. Afisare oferte : " << std::endl;
        std::cout << "0. Iesire : " << std::endl;
        std::cout << "Selectati optiunea dorita : ";
        std::cin  >> opt;

        switch(opt){
            case 1:
                introducere(l, 0);
                break;
            case 2:
                introducere(l, 1);
                break;
            case 3:
                l.afisare_lista();
                break;
            case 0:
                //exit case
                break; 
            default:
                std::cout << "Unavailable option " << std::endl;
                break;
        }
    }while(opt != 0);


    return 0;
}