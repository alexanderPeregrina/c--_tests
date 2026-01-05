#include <iostream>
#include <vector>
#include <string>

using namespace std;
using vec_of_vec = vector<vector<int>>;
string print_vector(vector<int>& my_vector)
{
  string my_string{};
  for(int i : my_vector)
  {
    my_string.append(to_string(i));
    my_string.append(" ");
  }
  return my_string;
}

int main()
{
  int my_int{7};
  float my_float{12.5};
  vector<int> my_vector{1, 2, 3, 4, 5};
  string my_string{"Hello world from hell"};
  vec_of_vec my_vec_of_vec{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

  cout << "The value of my_int is: " << my_int << endl;
  cout << "The value of my_float is: " << my_float << endl;
  cout << "The value of my_vector is: " << print_vector(my_vector)<< endl;
  for (vector<int> vec: my_vec_of_vec)
  {
     cout << "The value of my_vector is: " << print_vector(vec)<< endl;
  }
  cout << "The value of my_string is: " << my_string << endl;

}