#include <iostream>
using namespace std;

// Base and Derived classes for dynamic_cast
class Base {
public:
    // A virtual function is a member function in a base class that you expect to be overridden in derived classes.
    virtual void speak() { cout << "Base speaking\n"; }
};

class Derived : public Base {
public:
    void speak() override { cout << "Derived speaking\n"; }
};

int main() {
    // 1. static_cast
    double pi = 3.14159;
    int intPi = static_cast<int>(pi);
    cout << "static_cast: " << intPi << endl;

    // 2. dynamic_cast
    Base* basePtr = new Derived();
    Derived* derivedPtr = dynamic_cast<Derived*>(basePtr);
    if (derivedPtr) {
        cout << "dynamic_cast successful: ";
        derivedPtr->speak();
    } else {
        cout << "dynamic_cast failed\n";
    }

    // 3. const_cast
    // this also removes the volatile modifier
    const int x = 42;
    int& y = const_cast<int&>(x);
    y = 100; // Undefined behavior if x was truly const
    cout << "const_cast: x = " << x << ", y = " << y << endl;

    // 4. reinterpret_cast
    // commonluy used in  casting between pointers, function pointers
    int num = 65;
    char* charPtr = reinterpret_cast<char*>(&num);
    cout << "reinterpret_cast: " << *charPtr << endl;

    delete basePtr;
    return 0;
}
