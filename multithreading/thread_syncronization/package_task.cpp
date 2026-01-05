// similar to future and promise classes, but task is triggered when the functor is called
#include <future>
#include <thread>
#include <iostream>

using namespace std;


int main()
{

  packaged_task<int(int, int)> task{[](int a, int b){ return a + b;}};

  auto fut = task.get_future();

  thread t1{move(task), 5, 7};

  cout << "Waiting for the result" << endl;

  cout << "The result of 5 + 7 is "<< fut.get() << endl;

  t1.join();
  
  return 0;
}