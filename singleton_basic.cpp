#include <iostream>

class Singleton {
private:
    static Singleton* instance;

    // Private constructor to prevent instantiation
    Singleton() {
        std::cout << "Singleton instance created.\n";
    }

public:
    // Delete copy constructor and assignment operator
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

    // Static method to access the instance
    static Singleton* getInstance() {
        if (instance == nullptr) {
            instance = new Singleton();
        }
        return instance;
    }

    void doSomething() {
        std::cout << "Doing something with the singleton.\n";
    }
};

// Initialize the static member
Singleton* Singleton::instance = nullptr;

int main() {
    Singleton* s1 = Singleton::getInstance();
    Singleton* s2 = Singleton::getInstance();

    s1->doSomething();

    if (s1 == s2) {
        std::cout << "Both pointers point to the same instance.\n";
    }

    return 0;
}
