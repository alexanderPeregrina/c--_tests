#include<iostream>

using namespace std;

int main()
{
  int my_decimal = 10;
  int my_hexadecimal = 0x32;
  int my_octal = 0623;
  int my_binary = 0b0110011101;  
  long long my_longlong = 784'548'695'254;

  cout << my_decimal << endl;
  cout << my_hexadecimal << endl;
  cout << my_octal << endl;
  cout << my_binary << endl;
  cout << my_longlong << endl;

  return 0;
}