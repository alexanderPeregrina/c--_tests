#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main ()
{
  ifstream ifile{"example.txt"};

  string text;
  while(ifile >> text)
  {
    cout << text << ", " << endl;
  }
  return 0;
}