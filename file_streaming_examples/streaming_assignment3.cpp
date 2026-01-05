#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>

  struct language {
    std::string lang;
    std::string designer;
    int date;
};

int main()
{
  std::ifstream ifile{"languages.txt"};
 
  std::vector<language> languages;
  std::string line_str;

  if (ifile.is_open())
  {
    // Store all lines in vector
    while(getline(ifile, line_str))
    {
       std::istringstream input_string_streamer{line_str};
       language line_info;
       input_string_streamer >> line_info.lang;
       input_string_streamer >> line_info.designer;
       input_string_streamer >> line_info.date;
       languages.push_back(line_info);
    }
    ifile.close();
    // print all elements in vector
    for(auto it: languages)
    {
      std::cout << it.lang << ", " << it.designer << ", " << it.date << std::endl;
    }
  }
  else
  {
    std::cout << "Error while trying to read file."<< std::endl;
  }
  return 0;
}