#include <iostream>
#include <numeric>
#include <iterator>
#include <array>
#include <algorithm>

int main(){

    // std::array<int, 100> ids;

    // std::iota(std::begin(ids), std::end(ids), 0);

    // for(int i : ids){
    //     std::cout << i << std::endl;

    // }

    std::array<int , 3> myArray;
    std::fill(std::begin(myArray), std::end(myArray), 1024);

    for(int element : myArray){
        std::cout << element << std::endl;
    }

    return 0;
}