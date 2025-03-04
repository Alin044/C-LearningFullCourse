#include <iostream>
#include <vector>
#include <string>

class PrivateSecurityInfo{
    friend class UDT;
    private:
        int passcode;
};

class UDT{
    public:
        UDT(){
            m_privateVar = 0;
            m_Info.passcode = 7;
        }
        friend void printPrivateVariableMembers(UDT u);
        //friend class PrivateSecurityInfo;
    private:
        PrivateSecurityInfo m_Info;  // this class is friend of UDT, so it can access private members of UDT
        int m_privateVar;
};


void printPrivateVariableMembers(UDT u){
    std::cout << "Private variable : " << u.m_privateVar << std::endl;
}

int main(){

    UDT instance;


    return 0;
}