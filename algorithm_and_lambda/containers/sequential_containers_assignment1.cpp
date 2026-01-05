#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <forward_list>
#include <deque>

using namespace std;

  template<class T>
  void print(const T& container)
  {
    cout << "******************************Printing container*************************************"<<endl;
    for (auto it : container)
    {
        cout << it << endl;
    } 
  }


int main()
{
  vector<string> vec;
  forward_list<string> f_list;
  list<string> my_list;
  deque<string> my_deque;
  string input_string;

  
  do 
  {
    cout << "Enter a string: ";
    getline(cin, input_string);
    vec.push_back(input_string);
    f_list.push_front(input_string);
    my_list.push_front(input_string);
    my_deque.push_front(input_string);

  } while(input_string != "quit");
  
  print(vec);
  print(f_list);
  print(my_list);
  print(my_deque);

  return 0;
}
