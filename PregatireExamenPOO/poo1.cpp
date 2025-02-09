#include <iostream>

template<class TipVector> class vector{
    TipVector v[20];
    int index;
    public:
        vector(){
            index = 0;
        }
        void introducere(TipVector ob);
        void afisare();
};

template<class TipVector> void vector<TipVector>::introducere(TipVector ob){
    v[index] = ob;
    index++;
}

template<class TipVector> void vector<TipVector>::afisare(){
    if(index == 0){
        std::cout << "Vectorul este gol " << std::endl;
    }else{
        for(int i = 0; i < index; i++){
            std::cout << v[i] << " ";
        }
    }
}

int main(){
    
    vector<char> v1, v2;
    v1.introducere('a');
    v2.introducere('@');
    v1.introducere('b');
    v2.introducere('#');
    v1.introducere('c');
    v2.introducere('$');

    std::cout << "Vectorii cu elementele de tip char : " << std::endl;
    v1.afisare();
    std::cout << std::endl;
    v2.afisare();
    std::cout << std::endl;

    vector<double> x1, x2;
    x1.introducere(1.5);
    x2.introducere(2.2);
    x1.introducere(3.8);
    x2.introducere(4.7);
    x1.introducere(5.6);
    x2.introducere(6.4);

    std::cout << "Vectorii cu elemente de tip double : " << std::endl;
    x1.afisare();
    std::cout << std::endl;
    x2.afisare();
    std::cout << std::endl;

    return 0;
}