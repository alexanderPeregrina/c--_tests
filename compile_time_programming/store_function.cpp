#include <iostream>
#include<functional>

using namespace std;

int sum_integers(int a, int b)
{
  return a + b;
}

template <typename T>
void print(const T& value)
{
  cout << value << " ";
}


template <typename T, typename... Args>
void print(const T& first, const Args&... rest)
{
  cout << first << " ";
  print(rest...);
}

int main()
{
  function<int(int, int)> func = sum_integers;
  cout << "The sum is: "<< func(50, 70) << endl;

  // Create instance of template function
  function<void(string, int, string, int)> variadic_printer = print<string, int, string, int>; 

  variadic_printer("Alex:", 29, "Angelica: ", 32);
  cout << endl;

  return 0;
}