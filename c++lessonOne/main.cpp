#include <iostream>
#include <functional>
//function pointers 

typedef int (*integerOperations)(int, int);

int add(int a, int b){
    return a + b;
}

int multiply(int a, int b){
    return a * b;
}

int main(){

    std::function<int(int, int)> op;
    //int (*op)(int, int);
    integerOperations op; // the modern and more readable way to declare function pointers
    std::cout << "1 for add, 2 for multiply" << std::endl;
    int n;
    std::cin >> n;
    if(n == 1){
        op = add;
    }else{
        op = multiply;
    }
    

    std::cout << "Operation : " << op(2, 2) << std::endl;
    std::cout << "Operation : " << multiply(2, 2) << std::endl;

    return 0;
}