#include <string>

class IntArray{
    public:
        IntArray(std::string name);

        ~IntArray();

        IntArray(const IntArray& rhs);

        IntArray& operator=(const IntArray& rhs);

    private:
        std::string m_name;
        int* m_data;

};