#include <iostream>

using namespace std;

class Base 
{
  int base_int;
  public:
    Base(int base_int) : base_int(base_int)
    {

    }
    virtual void print()
    {
      cout << "Base Class" << endl;
    }
};

class Child : public Base 
{
  public:
  using Base::Base;
  void print()
  {
    cout << "Child Class" << endl;
  }
};

class GrandChild : public Child
{
  public:
  using Child::Child;
    void print()
    {
      cout << "Grand Child Class" << endl;
    }
};

void print_class(Base& base)
{
  base.print();
}

int main()
{
  Base base{10};
  Child child{20};
  GrandChild grandchild{15};
  print_class(base);
  print_class(child);
  print_class(grandchild);

  return 0;
}