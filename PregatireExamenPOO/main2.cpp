#include <iostream>

class Dreptunghi{
    int *latime, *inaltime;
    public:
        Dreptunghi(int, int);
        ~Dreptunghi();

        int calc_arie(){
            return (*latime * *inaltime);
        }
};

Dreptunghi::Dreptunghi(int l, int i){
    latime = new int;
    inaltime = new int;
    *latime = l;
    *inaltime = i;
}

Dreptunghi::~Dreptunghi(){
    delete latime;
    delete inaltime;
    std::cout << "Am eliberat cu succes memoria" << std::endl;
}

int main(){

    Dreptunghi da(3, 5), db(8, 5);

    std::cout << "Aria A : " << da.calc_arie() << std::endl;
    std::cout << "Aria B : " << db.calc_arie() << std::endl;

    da.~Dreptunghi();
    db.~Dreptunghi();

    return 0;
}