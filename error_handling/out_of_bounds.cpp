#include <iostream>
#include <vector>

using namespace std;

int main ()
{
  vector<int> my_vec{};

  try
  {
    cout << "Printing element 2" << my_vec.at(2) << endl;
  }
  catch(const exception& e)
  {
    cerr << e.what() << '\n';
  }
  
  return 0;
}