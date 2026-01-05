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

void process()
{
  /* Static local variables are initialized only once by the first thread reaches this code*/
  static Test test;
  test.func(); 

}

int main()
{
  thread thr1{process};
  thread thr2{process};

  thr1.join();
  thr2.join();
  
  return 0;
}