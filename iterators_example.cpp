#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
  string my_string = "This is a test string";
  vector <int> my_vec = {1, 2, 3, 4, 5};

  // using iterators
  for(auto it : my_string)
  {
    cout << it; 
  }
  cout << endl;

  // using const iterators
  for(auto i=my_string.cbegin(); i != my_string.cend(); ++i)
  {
    cout << *i; 
  }
  cout << endl;
   // using reverse iterators
  for(auto i=my_string.rbegin(); i != my_string.rend(); ++i)
  {
    cout << *i; 
  }
  cout << endl;

  // using const reverse iterators
  for(auto i=my_string.crbegin(); i != my_string.crend(); ++i)
  {
    cout << *i; 
  }
  cout << endl;

  // using global begin() and end()
  for(auto i=begin(my_string); i != end(my_string); ++i)
  {
    cout << *i; 
  }
  cout << endl;

  // Now using vectors
    // using iterators
  for(auto it : my_vec)
  {
    cout << it << " "; 
  }
  cout << endl;

  for(auto& it : my_vec)
  {
    it= it+2;
    cout << it << " "; 
  }
  cout << endl;

  for(auto it : my_vec)
  {
    cout << it << " "; 
  }
  cout << endl;

  // removing odd elements
  cout << "Removing odd elements" << endl;
  for(auto it = my_vec.begin(); it != my_vec.end();)
  {
    if ((*it % 2) != 0)
    {
      (void)my_vec.erase(it);
    }
    else
    {
      // only increment if no erase
     ++it;
    }
      
  }
  cout << endl;

  for(auto it : my_vec)
  {
    cout << it << " "; 
  }
  cout << endl;

}