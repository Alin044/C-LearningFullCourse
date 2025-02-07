//Liste simplu inlantuite
#include <iostream>
#include <cstring>

class Carte{
    char titlu[20], autori[40], editura[20];
    int anPublicare;
    Carte *next;

    public:
        Carte(const char* titlu, const char* autori, const char* editura, int anPublicare){
            strcpy(this->titlu, titlu);
            strcpy(this->autori, autori);
            strcpy(this->editura, editura);
            this->anPublicare = anPublicare;
            this->next = nullptr;
        }

        const char* getTitlu(){return titlu;}
        const char* getAutori(){return autori;}
        const char* getEditura(){return editura;}
        int getAnPublicare(){return anPublicare;}

        void setNext(Carte* nextCarte){next = nextCarte;}
        Carte* getNext(){return next;}

        void displayCarte(){
            std::cout << "Titlu: " << titlu << std::endl;
            std::cout << "Autori: " << autori << std::endl;
            std::cout << "Editura: " << editura << std::endl;
            std::cout << "An publicare: " << anPublicare << std::endl;
            std::cout << "-----------------------------" << std::endl;
        }
};

class ListaCarti{
    private:
        Carte* head;
    public:
        ListaCarti(){
            head = nullptr;
        }

        void addCarte(const char* titlu, const char* autori, const char* editura, int anPublicare){
            Carte* newNode = new Carte(titlu, autori, editura, anPublicare);
            
            if(head == nullptr){
                head = newNode;
                return;
            }
            Carte* temp = head;
            while(temp -> getNext() != nullptr){
                temp = temp -> getNext();
            }
            temp -> setNext(newNode);
        }

        void displayList(){
            if(head == nullptr){ std::cout << "Lista este goala" << std::endl; return;}
            Carte* temp = head;
            int i = 1;
            while(temp != nullptr){
                std::cout << i << ". Titlu : " << temp -> getTitlu() << std::endl;
                std::cout << "-Autori : " << temp -> getAutori() << std::endl;
                std::cout << "-Editura : " << temp -> getEditura() << std::endl;
                std::cout << "-Anul Publicarii : " << temp -> getAnPublicare() << std::endl;
                std::cout << "-----------------------------------------------------" << std::endl;
                temp = temp -> getNext();
            }
        }

        void deleteBook(const char* titlu){
            if(head == nullptr) return;

            if(strcmp(head -> getTitlu(), titlu) == 0){
                Carte* temp = head;
                head = head -> getNext();
                delete temp;
                return;
            }

            Carte* temp = head;
            while(temp -> getNext() != nullptr && strcmp(temp -> getNext()-> getTitlu(), titlu) != 0){
                temp = temp -> getNext();
            }

            if(temp -> getNext() == nullptr) return;

            Carte* toDelete = temp -> getNext();
            temp -> setNext(temp -> getNext() -> getNext());
            delete toDelete;
        }

        ~ListaCarti(){
            Carte* temp;
            while(head != nullptr){
                temp = head;
                head = head -> getNext();
                delete temp;
            }
        }
};




int main(){

    ListaCarti lista;

    lista.addCarte("C++ Basics", "John Doe", "TechPress", 2020);
    lista.addCarte("Data Structures", "Jane Smith", "EduBooks", 2018);
    lista.addCarte("Algorithms", "Alice Brown", "ScienceWorld", 2022);

    std::cout << "Lista cartilor:\n";
    lista.displayList();

    std::cout << "Stergem cartea 'Data Structures'\n";
    lista.deleteBook("Data Structures");

    std::cout << "Lista dupa stergere:\n";
    lista.displayList();

    return 0;
}


















