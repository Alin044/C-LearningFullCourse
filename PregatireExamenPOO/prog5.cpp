#include <iostream>
#include <cstring>

class student{
    char nume[80];
    char prenume[80];
    unsigned int varsta;
    int nr_matricol;

    public:
        student(const char* n, const char* p, unsigned int v, int nr){
            strcpy(nume, n);
            strcpy(prenume, p);
            varsta = v;
            nr_matricol = nr;
        }

        friend std::ostream& operator<<(std::ostream& iesire, student st);
};

std::ostream& operator<<(std::ostream& iesire, student st){
    //same thing, but u can access the private variables (see in prog4.cpp in this file)
}


int main(){

    return 0;
}