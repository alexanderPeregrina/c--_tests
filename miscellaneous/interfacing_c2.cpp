#include <iostream>
#include <map>
#include <algorithm> 
#include <vector> 
#include "array.h"

using namespace std;

int main()
{
  map<int, int> my_map{};
  vector<int> keys;
  vector<int> values;

  my_map.insert({1, 11});
  my_map.insert({2, 12});
  my_map.insert({3, 13});
  my_map.insert({4, 14});
  my_map.insert({5, 15});
  my_map.insert({1, 21});


  for (auto &it : my_map)
  {
    keys.push_back(it.first);
    values.push_back(it.second);
  }

  cout << "Map Keys" << endl; 
  print_array(keys.data(), static_cast<int>(keys.size()));

  cout << "Map values" << endl; 
  print_array(values.data(), static_cast<int>(values.size()));

  return 0;
}