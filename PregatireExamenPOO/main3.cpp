#include <iostream>

class Student {
    char nume[20], prenume[20];
    int grupa, codPostal;
    public:
        Student();
        ~Student();
        void citireDate();
        void afisareDate();
};

Student::Student(){
    std::cout << "Informatii despre student : " << std::endl;
}

void Student::citireDate(){
    std::cout << "Numbe : ";
    std::cin >> nume;
    std::cout << "Prenume : ";
    std::cin >> prenume;
    std::cout << "Grupa : ";
    std::cin >> grupa;
    std::cout << "CodPostal : ";
    std::cin >> codPostal;
    std::cout << std::endl;
}

void Student::afisareDate(){
    std::cout << "Nume : " << nume << std::endl;
    std::cout << "Prenume : " << prenume << std::endl;
    std::cout << "Grupa : " << grupa << std::endl;
    std::cout << "CodPostal : " << codPostal << std::endl;
}

Student::~Student(){
    std::cout << "Eliberarea memoriei";
}

int main(){ 
    Student s;
    s.citireDate();
    s.afisareDate();


    return 0;
}