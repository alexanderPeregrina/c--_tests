
#include <iostream>
#include <vector>
#include <algorithm> // for std::sort

int main() {
  //Create a vector of nubers
  std::vector<int> nums = {10, 20, 5, 6, 8, 9, -4, 8, 1};

  // Sort numbers in asecnding order
  std::sort(nums.begin(), nums.end());

  for(int num : nums)
  {
    std::cout<<num<<std::endl;
  }
  return 0;

}
