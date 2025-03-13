#include <iostream>

struct noncopyable{
    noncopyable() = default;
    noncopyable(const noncopyable& rhs) = delete;
    noncopyable& operator=(const noncopyable& rhs) = delete;
};

struct Dog : public noncopyable
{
    virtual void Bark(){
        std::cout << "Dog::Bark" << std::endl;
    }
};

struct BorderCollie : public Dog{
    virtual void Bark() override{
        std::cout << "BorderCollie::Bark" << std::endl;
    }
};

struct Golden : public Dog
{
    virtual void Bark() override{
        std::cout << "Golden::Bark" << std::endl;
    }
};

struct Coltriever : public Golden, BorderCollie
{
    void Bark() override{
        std::cout << "Coltriever::Bark" << std::endl;
    }
};
//Red flag, not very good to implement this method
int main(){

    // Dog dog2;
    // Dog dog3 = dog2;
    //error - noncopyable does not allow us to copy when pass by value

    Dog dog;
    Golden golden;
    BorderCollie borderCollie;
    Coltriever coltriever;

    dog.Bark();
    golden.Bark();
    borderCollie.Bark();
    coltriever.Bark();

    // Dog* dog = new Dog;
    // Dog* golden = new Golden;
    // Dog* borderCollie = new BorderCollie;
    // Dog* coltriever = new Coltriever;

    // dog -> Bark();
    // golden -> Bark();
    // borderCollie -> Bark();
    // coltriever -> Bark();


    return 0;
}