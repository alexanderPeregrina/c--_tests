/*

Write a function called exclaim(). This function takes an std::string as argument and returns an std::string.

The function will return the argument string, but with all the punctuation characters replaced by an exclamation mark.

For example, if the argument string is

"To be, or not to be, that is the question:"

The returned string will be

"To be! or not to be! that is the question!"

Use a suitable character function to implement this function.

Questions for this assignment
Implement the exclaim() function

Write a program to test your code. This program will call exclaim() and display the returned string.
*/
#include <iostream>
#include <string>
#include <cctype>


using namespace std;
string exclaim(string input_str)
{
  //string output_str = input_str;
  for(auto& it : input_str)
  {
    if(ispunct(it))
    {
      it = '!';
    }
  }  
  return input_str;
}


int main ()
{
  string test = "To be, or not to be, that is the question:";
  cout << exclaim(test) << endl;
  cout << test << endl;
  return 0;
}