#include <iostream>
#include <vector>

void printMyVec(const std::vector<int>& vec){
    for(int i = 0; i < vec.size(); i++){
        std::cout << vec[i] << std::endl;
    }
}

int main(){

    std::vector<int> myVec = {1, 3, 5, 7, 9};

    printMyVec(myVec);

    // int n;
    // std::cout << "Enter number of students: " << std::endl;
    // std::cin >> n;
    // int* studentids = new int[n];

    // for(int i = 0; i < n; i++){
    //     studentids[i] = i;
    // }

    // delete[] studentids;

    return 0;
}