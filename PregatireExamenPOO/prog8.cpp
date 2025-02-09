#include <iostream>
#include <fstream>
#include <string>

int main(){

    std::ifstream fis("Fisier.txt");
    std::string linie_fisier;

    if(fis.is_open()){
        while(getline(fis, linie_fisier)){
            std::cout << linie_fisier << std::endl;
        }
        fis.close();
    }else
        std::cout << "Eroare la deschiderea fisierului " << std::endl;

    return 0;
}