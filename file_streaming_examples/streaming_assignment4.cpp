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
  std::ifstream ifile{"languages2.txt"};
 
  std::vector<language> languages;
  std::string line_str, temp_str;

  if (ifile.is_open())
  {
    // Store all lines in vector
    while(getline(ifile, line_str))
    {
       std::istringstream input_string_streamer{line_str};
       language line_info;
       input_string_streamer >> line_info.lang;
       while(input_string_streamer >> temp_str)
       {
          try
          {
            line_info.date = std::stoi(temp_str);
          }
          catch(const std::exception& e)
          {
            line_info.designer.append(temp_str);
            line_info.designer.append(" ");
          }
          

       }
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