#ifndef ARRAY_HPP
#define ARRAY_HPP

class Array{
    public:
        //special member functions
        //1. constructor
        Array();
        //destructor
        ~Array();

        void PrintingData();

        void SetData(int index, int value);
        //copy constructor
        //
        Array(const Array& rhs);

        //copy assignment operator
        //object is already constructed
        //makeing a copy later (myArray2 = myArray)
        Array& operator = (const Array& rhs);
        
    private:
        int* data;
};

#endif