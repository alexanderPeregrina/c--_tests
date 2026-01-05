#include <iostream>

using namespace std;

void passing_by_value(int value);

void passing_by_address(int * p_value);

void passing_by_reference(int& value);

void passing_by_value(int value)
{
  cout << "The value of the argument is: " << value << endl;
}

void passing_by_address(int * p_value)
{
  cout << "The value of the argument is: " << p_value << endl;
}

void passing_by_reference(int& value)
{
  cout << "The value of the argument is: " << value << endl;
  cout << "The value of the argument address is: " << &value << endl;
}

int main()
{
  int value = 100;
  int *p_value = &value;
  
  passing_by_value(value);
  passing_by_address(p_value);
  passing_by_reference(value);

}