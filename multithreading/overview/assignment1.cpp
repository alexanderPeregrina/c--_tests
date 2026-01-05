/*
Write a program which:

Defines a vector whose elements have type int. Use universal initialization to set its values to 4, 2, 3, 5 and 1, in that order.

Uses a range-for loop to display all the elements of the vector in order. Use the auto keyword for the type of the elements.

Uses a range-for loop to add 2 to all the elements.

Uses a range-for loop to display all the elements of the vector again.
*/
#include <vector>
#include <iostream>

int main()
{
  std::vector<int> v{4, 2, 3, 5, 1};

  for (auto it : v)
  {
    std::cout << it << " ";
  }

   std::cout << std::endl;

   for(auto& it : v)
   {
    it += 2;
   }

   for(auto it: v)
   {
    std::cout << it <<" ";
   }
   std::cout << "\n";

  return 0;
}