#include <iostream>

using namespace std;

class Sample {
public:
    Sample() {
        cout << "Sample class constructor called.\n";
    }
    template <typename T>
    void printValue(T value) {
        cout << "Value: " << value << '\n';
    }
};

template <typename T>
class TemplateClass{
public:
    T data;
    TemplateClass(T val) : data(val) {}
    void displayData() {
        cout << "Data: " << data << '\n';
    }
    template <typename U>
    void printDifferentType(U otherData) {
        cout << "Other Data: " << otherData << '\n';
    }
};

int main() {

    cout << "This file demonstrates classes and templates in C++.\n";
    Sample sample;
    sample.printValue(76);
    sample.printValue(3.14f);
    sample.printValue("Hello, Templates!");

    // Now using a template class with a template member function
    TemplateClass<int> intObj(42);
    intObj.displayData();
    intObj.printDifferentType(3.14159f);
    TemplateClass<string> strObj("Template Class");
    strObj.displayData();   
    strObj.printDifferentType(100);
    return 0;

}