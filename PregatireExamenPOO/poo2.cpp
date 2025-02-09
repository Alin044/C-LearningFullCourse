#include <iostream>
#include <vector>


int main(){
    std::vector<int> v;
    int i;

    std::cout << "Dimensiune vector = " << v.size() << std::endl;

    for(i = 0; i < 5; i++){
        v.push_back(i);
    }

    std::cout << "Extended vector size = " << v.size() << std::endl;

    for(i = 0; i < 5; i++){

    }
    return 0;
}