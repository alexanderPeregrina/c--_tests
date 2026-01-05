#include <string>
#include <iostream>

using namespace std;

int main()
{
  string message{"This is the complete string, search here"};

  string substring{"search here"};

  auto position = message.find(substring);

  if (position != string::npos)
  {
    cout << "The substring found is: " << message.substr(position);
  }
  return 0;
}