#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
using namespace std;

int main()
{
  ifstream ifile{"numbers.txt"};
  ostringstream string_builder{};
  vector<int> numbers{};

  if (ifile.is_open())
  {
    int number;
    while(ifile >> number)
    {
      numbers.push_back(number);
    }

    for(auto it : numbers)
    {
      string_builder << it << " ";
    }
  }
  else
  {
    cout << "Error while trying to open the file" << endl;
  }

  cout << string_builder.str() << endl;



  return 0;
}