#include <iostream>
#include <numeric>
#include <iterator>
#include <array>
#include <algorithm>

int add(int a, int b);
auto add(float a, float b) -> float;

int countdown(int n){
    // 1. Base case 
    //
    if(n == 0){
        std::cout << "Blast off" << std::endl;
        return 0;
    }

    // Recursive Case
    std::cout << n << std::endl;
    return countdown(n - 1); 
}

int main(){

    // std::array<int, 100> ids;

    // std::iota(std::begin(ids), std::end(ids), 0);

    // for(int i : ids){
    //     std::cout << i << std::endl;

    // }

    /*
    std::array<int , 3> myArray;
    std::fill(std::begin(myArray), std::end(myArray), 1024);

    for(int element : myArray){
        std::cout << element << std::endl;
    }
    */



/*
   for(int i = 0; i < 10; i++){
    std::cout << "start of loop" << std::endl;
    continue;
    std::cout << i << std::endl;
   }

    for(int i = 0; i < 10; i++){
        std::cout << "start of loop" << std::endl;
        if(i == 5){
            break;
        }
        std::cout << i << std::endl;
    }
    */


   //recursion 

   countdown(8);



    return 0;
}

// int add(int a, int b){
//     return a + b;
// }

// float add(float a, float b){
//     return a + b;
// }