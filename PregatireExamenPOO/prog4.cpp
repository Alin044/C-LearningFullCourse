#include <iostream>
#include <cstring>

class student{
    public:
        char nume[80];
        char prenume[80];
        unsigned int virsta;
        int nr_matricol;

        student(const char* n, const char* p, unsigned int v, int nr){
            strcpy(nume, n);
            strcpy(prenume, prenume);
            virsta = v;
            nr_matricol = nr;
        }
};

std::ostream &operator<<(std::ostream &iesire, student st){
    iesire << st.nume << " " << st.prenume;
    iesire << " are " << st.virsta << " ani";
    iesire << " numar matricol " << st.nr_matricol << std::endl;
    return iesire;
}


int main(){
    student a("Popescu", "Ioana", 19, 2345);
    student b("Lupse", "Oana", 21, 1385);

    std::cout << a << b;
    return 0;
}