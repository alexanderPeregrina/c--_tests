#include <iostream>
#include <algorithm>
#include <vector> 
using namespace std;

void print_array_elements(vector<int>& vec)
{
  for(auto it : vec)
  {
    cout << it <<" ";
  }
  cout << endl;
}

int main ()
{
  vector<int> vec{1, 2, 3, 4, 5};

  sort(vec.begin(), vec.end(), [] (int n, int m) {return (n > m); });

  print_array_elements(vec);

  return 0;
}