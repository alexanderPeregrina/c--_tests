#include <iostream>

template <int N>
int fibonacci()
{
    return fibonacci<N - 1>() + fibonacci<N - 2>();
}

template <>
int fibonacci<0>()
{
    return 0;
}

template <>
int fibonacci<1>()
{
    return 1;
}

int main()
{
    constexpr int n_10 = 10 ;
    int fib_10 = fibonacci<n_10>();
    std::cout << "Fibonacci of 10 is: " << fib_10 << '\n';
    return 0;
}