#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <sstream>
#include <utility>

using namespace std;

int main ()
{
  string input_string;
  cout << "Enter a line: ";
  getline(cin, input_string); 
  istringstream string_streamer{input_string};
  map<string, int> word_info_vec{};
  string streamed_word{};

  while (string_streamer >> streamed_word)
  {
    word_info_vec[streamed_word] = streamed_word.size();
  }

  for (auto it : word_info_vec)
  {
    cout << "Word: " << it.first << ", Length: " << it.second << endl;
  }
  
  return 0;
}