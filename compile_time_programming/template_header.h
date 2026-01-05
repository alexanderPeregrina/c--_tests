#ifndef TEMPLATE_HEADER_H
#define TEMPLATE_HEADER_H
#include <iostream>
#include <typeinfo>

using namespace std;

template <typename T>
void displayTypeInfo(T value)
{
  cout << "Type: " << typeid(T).name() << ", Value: " << value << '\n';    
}

#endif // TEMPLATE_HEADER_H
