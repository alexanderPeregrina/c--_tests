#include <iostream>

using namespace std;

int main()
{
  char my_char{0};
  short my_short_int{0};
  int my_int{0};
  long my_long{0};
  long long my_double_long{0};

  cout << "The size of char is: " << sizeof(my_char) << endl;
  cout << "The size of short int is: " << sizeof(my_short_int) << endl;
  cout << "The size of int is: " << sizeof(my_int) << endl;
  cout << "The size of long int is: " << sizeof(my_long) << endl;
  cout << "The size of long long is: " << sizeof(my_double_long) << endl;

  return 0;
}