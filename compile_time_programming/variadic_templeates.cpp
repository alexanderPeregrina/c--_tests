#include <iostream>

using namespace std;

//base case: no arguments
void variadicFunctionHelper(bool firstCall)
{
  cout << endl;
}
// recursive variadic template function to handle multiple arguments
template <typename T, typename... Args>
void variadicFunctionHelper(bool firstCall, T t, Args... args)
{
    if (firstCall)
        cout << "Variadic Function called with arguments: " << sizeof...(args) + 1 << " arguments: ";
  cout << t << " ";
  variadicFunctionHelper(false, args...);
}

template <typename... Args>
void variadicFunction(Args... args)
{
    variadicFunctionHelper(true, args...);
}

int main()
 {
    cout << "This file demonstrates variadic templates in C++.\n";
    variadicFunction(1, 2.5, "Hello", 'A');
    variadicFunction("Only one argument");  
    variadicFunction(); // No arguments
    variadicFunction(42, 3.14f, "Test", true, 'Z', 100L);

    return 0;
}