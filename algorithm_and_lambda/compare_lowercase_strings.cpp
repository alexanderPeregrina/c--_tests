#include <iostream>
#include <algorithm>
#include <string> 
using namespace std;

bool are_lowercase_equal(const string& str1, const string& str2)
{
  return equal(str1.begin(), str1.end(), str2.begin(), str2.end(), [] (char a, char b) {return (tolower(a) == tolower (b));} );
}

int main ()
{

  string str1 = "Hello World";
  string str2 = "hello world2";

  if (are_lowercase_equal(str1, str2))
  {
    cout << str1 << " & " << str2 << " string are equal";
  }
  else 
  {
    cout << str1 << " & " << str2 << " string are not equal";
  }

  return 0;
}