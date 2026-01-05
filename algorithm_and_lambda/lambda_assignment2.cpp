#include <iostream>

using namespace std;

int main ()
{
  int y = 1;
  auto lamb = [y = y+1](int x) { return x + y; };
  cout << lamb(5) << endl;
  cout << y << endl;
  return 0;
}