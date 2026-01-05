#include <iostream>

// A constexpr function to compute the factorial of a number at compile time
constexpr int factorial(int n) {
    return (n <= 1) ? 1 : (n * factorial(n - 1));
}

int main() {
    // Compile-time computation
    constexpr int compileTimeFactorial = factorial(5);

    // Run-time computation
    int num;
    std::cout << "Enter a number: ";
    std::cin >> num;
    int runTimeFactorial = factorial(num);

    std::cout << "Factorial of 5 (computed at compile-time): " << compileTimeFactorial << '\n';
    std::cout << "Factorial of " << num << " (computed at run-time): " << runTimeFactorial << '\n';

    return 0;
}