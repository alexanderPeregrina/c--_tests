// requires C++17 compiler
#include <iostream>

using namespace std;

template<int N>
constexpr int fibonacci()
{
    if constexpr (N > 1)
        return fibonacci<N - 1>() + fibonacci<N - 2>();
    return N;
}

int main()
{
  std::cerr << "Program started!" << std::endl;
  constexpr int n_12 = 12 ;
  int fib_12 = fibonacci<n_12>();   
  cout << "Fibonacci of 12 is: " << fib_12 << '\n';
  system("pause"); // Windows only
}