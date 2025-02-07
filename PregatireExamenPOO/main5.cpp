#include <iostream>
#include <cstring>

class Persoana{
    char nume[30], prenume[30];
    int varsta;
    public:
        Persoana(char* nume, char* prenume, int varsta){
            strcpy(Persoana::nume, nume);
            strcpy(Persoana::prenume, prenume);
            Persoana::varsta = varsta;
            std::cout << "Constructorul clasei Persoana" << std::endl;
        }
    
        void displayPersoana(){
            std::cout << "Nume : " << nume << std::endl;
            std::cout << "Prenume : " << prenume << std::endl;
            std::cout << "Varsta : " << varsta << std::endl;
            std::cout << "===============================" << std::endl;
        }
};

class Student : public Persoana{
    int idStudent;
    int bursa;
    public:
        Student(char* nume, char* prenume, int varsta, int idStudent, int bursa):Persoana(nume, prenume, varsta){
            Student::idStudent = idStudent;
            Student::bursa = bursa;
            std::cout << "Constructorul clasei Student" << std::endl;
        }
        
        void displayStudent(){
            displayPersoana();
            std::cout << "Student : " << idStudent << std::endl;
            std::cout << "Bursa : " << bursa << std::endl;
            std::cout << "===============================" << std::endl;
        }
};

class Angajat : public Persoana{
    int idAngajat;
    float salariu;
    public:
        Angajat(char* nume, char* prenume, int varsta, int idAngajat, float bursa):Persoana(nume, prenume, varsta){
            Angajat::idAngajat = idAngajat;
            Angajat::salariu = bursa;
            std::cout << "Constructorul clasei Angajat" << std::endl;
        }
        
        void displayAngajat(){
            displayPersoana();
            std::cout << "Angajat : " << idAngajat << std::endl;
            std::cout << "Salariu : " << salariu << std::endl;
            std::cout << "===============================" << std::endl;
        }
};

class StudentLicenta : public Student {
    char specialitate[40];
    int aniDeStudii;
    public:
        StudentLicenta(char* nume, char* prenume, int varsta, int idStudent, int bursa, char* specialitate, int aniDeStudii)
        :Student(nume, prenume, varsta, idStudent, bursa){
            strcpy(StudentLicenta::specialitate, specialitate);
            this->aniDeStudii = aniDeStudii;
        }

        void displayStudentLicenta(){
            displayStudent();
            std::cout << "Specialitate : " << specialitate << std::endl;
            std::cout << "Ani de studii : " << aniDeStudii << std::endl;
            std::cout << "===============================" << std::endl;
        }
};

class StudentMaster : public Student {
    char specialitate[40];
    char facultate[40];
    public:
        StudentMaster(char* nume, char* prenume, int varsta, int idStudent, int bursa, char* specialitate, char* facultate)
        :Student(nume, prenume, varsta, idStudent, bursa){
            strcpy(this->specialitate, specialitate);
            strcpy(this->facultate, facultate);
            std::cout << "Constructorul clasei StudentMaster" << std::endl;
        }

        void displayStudentMaster(){
            displayStudent();
            std::cout << "Specialitate : " <<specialitate << std::endl;
            std::cout << "Facultate : " << facultate << std::endl;
            std::cout << "===============================" << std::endl;
        }
};

class Doctorand : public Student{
    char specialitate[40];
    int grad;
    public:
        Doctorand(char* nume, char* prenume, int varsta, int idStudent, int bursa, char* specialitate, int grad)
        :Student(nume, prenume, varsta, idStudent, bursa){
            strcpy(this->specialitate, specialitate);
            this->grad = grad;
            std::cout << "Constructorul Clasei Doctorand" << std::endl;
        }

        void displayDoctorand(){
            displayStudent();
            std::cout << "Specialitate : " << specialitate << std::endl;
            std::cout << "Grad : " << grad << std::endl;
            std::cout << "===============================" << std::endl;
        }
};

class Profesor : public Angajat{
    char disciplina[40];
    int gradDidactic;
    public:
        Profesor(char* nume, char* prenume, int varsta, int idAngajat, float salariu, char* disciplina, int gradDidactic)
        :Angajat(nume, prenume, varsta, idAngajat, salariu){
            strcpy(this->disciplina, disciplina);
            this->gradDidactic = gradDidactic;
            std::cout << "Constructorul Clasei Profesor" << std::endl;
        }

        void displayProfesor(){
            displayAngajat();
            std::cout << "Disciplina Profesor : " << disciplina << std::endl;
            std::cout << "Grad Didactic : " << gradDidactic << std::endl;
            std::cout << "===============================" << std::endl;
        }
};

class Inginer : public Angajat {
    char domeniu[40];
    int aniExperienta;
    public:
        Inginer(char* nume, char* prenume, int varsta, int idAngajat, float salariu, char* domeniu, int aniExperienta)
        :Angajat(nume, prenume, varsta, idAngajat, salariu){
            strcpy(this->domeniu, domeniu);
            this->aniExperienta = aniExperienta;
            std::cout << "Constructorul Clasei Inginer" << std::endl;
        }

        void displayInginer(){
            displayAngajat();
            std::cout << "Domeniu : " << domeniu << std::endl;
            std::cout << "Ani Experienta : " << aniExperienta << std::endl;
            std::cout << "===============================" << std::endl;
        }
};  

int main(){
    StudentLicenta st("Vova", "Carova", 20, 14167, 900, "Informatica", 3);
    st.displayStudentLicenta();

    return 0;
}