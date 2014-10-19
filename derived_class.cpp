#include <iostream>

class Base
{
public:
    void identify() const
    {
        std::cout << "base\n";
    }

    virtual void videntify() const
    {
        std::cout << "base\n";
    }
};

class Derived : public Base
{
public:
    void identify() const
    {
        std::cout << "derived\n";
    }

    void videntify() const
    {
        std::cout << "derived\n";
    }
};

int main(int argc, char** argv)
{
    Base* b = new Derived;
    b->identify();
    b->videntify();

    return 0;
}
