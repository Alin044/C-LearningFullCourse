#include <iostream>
#include <string>


int main(){

    std::string s1 = "Mike";
    std::string s2 = "A long string";
    std::string&& s3 = s1 + s2;
    std::cout << s3 << std::endl;

    return 0;
}