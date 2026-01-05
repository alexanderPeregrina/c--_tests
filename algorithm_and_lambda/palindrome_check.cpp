#include <iostream>
#include <algorithm>
#include <string>
#include <cctype>

using namespace std;

int main()
{
  string str = "Madam I'm Adam";
  string str2 = "";
  string str3 = "";

  copy_if(cbegin(str), cend(str), back_inserter(str2), [] (char c) {return isalpha(c);});
  transform(begin(str2), end(str2), begin(str2), [] (char c) {return tolower(c);});
  cout << "The string without punctuation is" << endl;
  cout << str2 << endl;

  reverse_copy(cbegin(str2), cend(str2), back_inserter(str3));

  cout << "Str2: " << str2 <<endl;
  cout << "Str3: " << str3 << endl;

  if (str2 == str3)
  { 
    cout << "The string is a palindrome" << endl;
  } 
  else
  {
    cout << "The string is  not a palindrome" << endl;
  }


  return 0;
}