#include <iostream>
#include <fstream>


int main(){
    std::ofstream fis;

    fis.open("Fisier1.txt");

    if(fis.is_open()){
        fis << "Prima linie intr-un fisier." << std::endl;
        fis.close();
    } else {
        std::cout << "Eroare la deschiderea fisierului" << std::endl;
    }

    return 0;
}