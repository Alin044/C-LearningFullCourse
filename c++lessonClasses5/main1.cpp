#include <iostream>
#include <string>

class Collection{
    public:
        Collection(){
            data = new int[10];
        }
        ~Collection(){
            delete[] data;
        }

        int& operator[](std::size_t idx){
            return data[idx];
        }

        const int& operator[](std::size_t idx)const{
            return data[idx];
        }
    private:
        int* data;
};

int main(){

    



    return 0;
}