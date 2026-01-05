#include<iostream>

using namespace std;

int main ()
{
  int my_var{50};
  int *p_my_var{&my_var};

  cout << "Value of the pointer " << p_my_var << endl;
  cout <<"De-referencing the pointer "<< *p_my_var << endl;
  return 0;
}
