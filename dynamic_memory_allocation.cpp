#include <iostream>
#include <string>
using namespace std;


int main ()
{

  int array_size;
  cout << "Please Enter an array size: ";
  cin >> array_size;
  auto my_array{new int[array_size]};
  //int my_array[array_size]; 
  cout << "[ " ;
  for(int i = 0; i <  array_size; ++i)
  {
    my_array[i] = i * 2;
    cout <<" " << my_array[i] <<" ,";
  }
  cout << "]" << endl;
  delete [] my_array; // to delete the entire array
  return 0;
}