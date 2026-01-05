#include <iostream>

using namespace std;


// alis for a func_pointer
using func_ptr = int (*)(int, int);

int maximum(int a , int b)
{
  if (a > b)
    return a;
  return b;
}

int minimum(int a , int b)
{
  if (a < b)
    return a;
  return b; 
}

int operation(int a, int b, func_ptr func)
{
  return func(a, b);
}


int main()
{
  int a = 100;
  int b = 200;
  auto p_min = minimum;
  auto p_max = maximum;
  /*
  func_ptr my_func = func; 
  int max_value = p_func(5, 7); */

  cout << "The maximum value is: " << operation(a, b, p_max) << endl; 
  cout << "The minium value is: " << operation(a, b, p_min) << endl; 

  return 0;
}