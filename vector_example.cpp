#include <iostream>
#include <vector>

using namespace std;

int main()
{
  vector<int> my_vec;

  my_vec.push_back(4);
  my_vec.push_back(2);
  my_vec.push_back(3);
  my_vec.push_back(4);
  my_vec.push_back(1);


  cout <<"The first element of my_vec is "<<my_vec[0]<<endl;
  cout <<"The forth element of my_vec is "<<my_vec[3]<<endl;
  my_vec[2] = 6;
  for (int i :  my_vec)
  {
    cout << i << " ";  
  }
  cout << endl;

}