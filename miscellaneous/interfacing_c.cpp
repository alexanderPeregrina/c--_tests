#include <iostream>
#include <set>
#include <algorithm> 
#include <vector> 
#include "array.h"

using namespace std;

int main()
{
  set<int> my_set{1, 2, 3, 4, 5, 5};
  vector<int> my_vect;

  
// Reserve space and copy elements from set to vector
  my_vect.reserve(my_set.size());


  copy(begin(my_set), end(my_set), back_inserter(my_vect));


  print_array(my_vect.data(), static_cast<int>(my_vect.size()));

  return 0;
}