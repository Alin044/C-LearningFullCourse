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

        MyException(char *s, int e){
            strcpy(str_what, s);
            what = e;
        }
};

void Lista::adaugare(agentie* a){
    
}



int main(){

    return 0;
}