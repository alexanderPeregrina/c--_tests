#include <iostream>
#include <tuple>
#include <utility>

using namespace std;

template<typename Tuple, size_t... Is>
void printTupleImpl(const Tuple& t, index_sequence<Is...>) {
    ((cout << get<Is>(t) << endl), ...);
}

template<typename... Ts>
void printTuple(const tuple<Ts...>& t) {
    printTupleImpl(t, index_sequence_for<Ts...>{});
}



int main ()
{
  tuple<double, int, string> t1{1.0, 2, "Three"s};

  cout << "The first element of the tuple is " << get<0>(t1) << endl; 
  get<1>(t1) = -2;
  cout << "The second element of the tuple is " << get<1>(t1) << endl; 

  cout << "The element of type string is " << get<string>(t1) << endl; 

  double d;
  int i;
  string st{};

  // looping through elements
  printTuple(t1);


  tie(d, i, st) = t1;

  cout << "d = " << d << endl;
  cout << "i = " << i << endl;
  cout << "st = " << st << endl;


  return 0;
}