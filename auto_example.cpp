#include <iostream>
#include <vector>
using namespace std;

int main()
{
// example 1
  vector<int> my_vect = {1, 2, 3, 4, 5};
  auto it = my_vect.begin();

  while(it != my_vect.end())
  {
    cout << *it << " ";
    it++;
  }
  cout << "\n";

  // example 2
  const int x = 10;
  auto &y{x};
  auto z{y};

  cout << "the value of x is: " << x << endl;
  cout << "the value of y is: " << y << endl;
  cout << "the value of z is: " << z << endl;
  z = z + 1;
  cout << "the value of z + 1 is: " << z << endl;
  cout << "the value of x is: " << x << endl;


}