#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

class Test
{
public:
  Test()
  {
    cout << "Constructor called" << endl;
  }

  void func()
  {

  }
};

Test *p_test = nullptr;
once_flag p_test_flag; 

void process()
{
    call_once(p_test_flag, [](){ p_test = new Test();});
    p_test->func();
}

int main()
{
  thread thr1{process};
  thread thr2{process};

  thr1.join();
  thr2.join();
  
  return 0;
}