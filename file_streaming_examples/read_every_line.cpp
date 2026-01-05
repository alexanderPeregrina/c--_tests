#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main ()
{
  ifstream ifile{"example.txt"};

  string text;
  while(getline(ifile, text))
  {
    cout << text << endl;
  }

  ifile.close();
  return 0;
}