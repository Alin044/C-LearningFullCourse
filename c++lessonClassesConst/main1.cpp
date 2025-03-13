#include <iostream>

class UserDefinedType{
    public:
        UserDefinedType(){

        }
        ~UserDefinedType(){

        }
        UserDefinedType(const UserDefinedType& rhs){

        }

        void ComputeValue() const {
        }

        void SetValue(int newValue){
            m_value = newValue;
        }

        int getValue() const {
            ComputeValue();
            return m_value;
        }
    private:
        int m_value;
};
//making all of the member variable in a member function read only
int main(){

    const float myNumber = 2.5f;
    UserDefinedType u;
    u.SetValue(100);


    return 0;
}