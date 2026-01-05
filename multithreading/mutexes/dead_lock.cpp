/* Deadlock Example:*/
#include <iostream>
#include <thread>
#include <mutex>

using namespace std;
mutex m1, m2;

void process_threadA()
{
  lock_guard lck_guard(m1);
  cout << "Processing Thread A" << endl;
  cout << "Waiting for thread B to unlock mutex 2" << endl;
  lock_guard lck_guard2{m2};
  cout << "Thread B unlock m2 mutex" << endl;
  cout << "Finishing process" << endl;
  
}

void process_threadB()
{
  lock_guard lck_guard(m2);
  cout << "Processing Thread B" << endl;
  cout << "Waiting for thread A to unlock mutex 1" << endl;
  lock_guard lck_guard2{m1};
  cout << "Thread a unlock m1 mutex" << endl;
  cout << "Finishing process" << endl;
  
}

int main()
{
  thread thr1{process_threadA};
  thread thr2{process_threadB};

  thr1.join();
  thr2.join();
  return 0;
}