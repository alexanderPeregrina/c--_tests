#include <iostream>
#include <string>

using namespace std;

int main()
{
  string my_string = "Hello";
  string my_string2 = "World";
  cout <<"The first element of my_string is "<<my_string[0]<<endl;
  cout <<"The fifth element of my_string is "<<my_string[4]<<endl;
  my_string[3] = 'b';
  cout << "The whole string is: "<< my_string << endl;
  cout << my_string + " "s + my_string2 << endl; 
}