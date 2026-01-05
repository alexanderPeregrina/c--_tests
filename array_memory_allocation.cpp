#include <iostream>

using namespace std;

int main()
{
  int *p_array = new int[20]; //equivalent to malloc

  "Fill all elements and print all elements";
  for(int i = 0; i < 20; ++i)
  {
    p_array[i] = i * 2;
    cout << "Array element "<< i <<": "<< p_array[i]<< endl;
  }

  delete [] p_array;
  
}