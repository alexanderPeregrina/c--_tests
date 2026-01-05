/* Deadlock Solution: lock multiple mutexes at the same time */
#include <iostream>
#include <thread>
#include <mutex>

using namespace std;
mutex m1, m2;

void process_threadA()
{
  scoped_lock my_lock(m1, m2);
  cout << "Processing Thread A" << endl;
  cout << "Thread A locking mutex m1 and m2" << endl;
  cout << "Finishing process" << endl;
  
}

void process_threadB()
{
  scoped_lock my_lock(m1, m2);
  cout << "Processing Thread B" << endl;
  cout << "Thread B locking mutex m1 and m2" << endl;
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