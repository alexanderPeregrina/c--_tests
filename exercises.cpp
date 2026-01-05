/*
    Problem statement:
    Implement a function template `findIndicesWithSum` that takes a std::vector<T> 
    and a target sum of type constexpr T. 
    This function should return a `std::map<std::pair<size_t, size_t>, T>` where
    each key is a pair of indices (i, j) from the vector such that the sum of elements at these indices
    is equal to the target sum, and the value is the target sum itself.
    Requirements: 
    Template Function: 
    The function should be able to work with any numeric type supported by 
    the standard operations (+) and should use template parameters appropriately. 
    Using STL Containers: 
    Use std::vector<T> to store input elements. 
    Use std::map<std::pair<size_t, size_t>, T> to store pairs of indices as keys 
    and the sum as the value when the elements at these indices sum up to the target.
    Example:
    For std::vector<int> v = {2, 3, 5, 7, 11} and constexpr int target = 10;, the output should be: 
    {   
        {(1, 3), 10}  
    } 
*/
#include <iostream>
#include <utility>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;


template<typename T>
map<pair<size_t, size_t>, T> findIndicesWithSum(vector<T>& vec, int target)
{
  map<int, int> seen{};
  map<pair<size_t, size_t>, int> return_map; 

  for (size_t i = 0; i < vec.size(); ++i)
  {
    int complement = target - vec[i];

      if(seen.find(complement) != seen.end())
      {
        cout << "I was here WTF" << endl;
        return_map[{seen[complement], i}] = target;
        return return_map;
      }
    seen[vec[i]] = i;
  }
  return return_map;
}

int main()
{
  vector<int> v = {2, 3, 5, 7, 11};
  map<pair<size_t, size_t> , int> vec_index = findIndicesWithSum(v, 10);

  for (auto my_pair : vec_index)
  {
    cout << "{i, j}, target}: " << my_pair.first.first << " " << my_pair.first.second << " " << my_pair.second << endl;
  }
  return 0;
}
