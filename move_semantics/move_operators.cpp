#include <iostream>

using namespace std;

class MyClass
{

};

class Test 
{
  private:
    int i{0};
    MyClass m;
  public:
    Test() = default;

    // Copy Constructor
    Test(const Test& arg): i(arg.i), m(arg.m)
    {
      cout << "Copy Constructor called" << endl;
    }

    // Move constructor
    Test(Test&& arg) noexcept : i(arg.i), m(move(arg.m))
    {
       cout << "Move Constructor called" << endl;
    }

    //Copy assignment operator
    Test& operator=(const Test& arg) 
    {
        cout << "Copy assignment operator called"<< endl;
        this->i = arg.i;
        this->m = arg.m;

        return *this;
    }

    // Move assignment operator
    Test& operator=(Test&& arg)
    {
      cout << "Move assignment operator called" << endl;
      if (this != &arg)
      {
        this->i = arg.i;
        this->m = move(arg.m);
      }
      return *this;
    }
};

int main()
{
  // call default constructor
  Test test{};

  // call copy constructor
  Test t1 = Test(test);

  // call move constructor by temporary object
  Test t2 = Test();

  // call move constructor by casting to rvalue
  Test t3 = move(t1);

  // call copy assignment operator
  Test t4 = t1;

  // call  move assignment operator
  Test t6;
  t6 = Test();
  
  return 0;
}