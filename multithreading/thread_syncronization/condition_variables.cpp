#include <condition_variable>
#include <mutex>
#include <thread>
#include <iostream>

using namespace std;
using namespace std::literals;

mutex m1;
condition_variable cond_var;

void read()
{
  unique_lock locker{m1};
  cout << "Thread A executing read process\n";
  cout << "Thread A waiting for write process to complete\n";
  cond_var.wait(locker);
  cout << "Thread A Finsing Read process\n";
}

void write()
{
  lock_guard locker{m1};
  cout << "Thread B executing write process \n";
  this_thread::sleep_for(5s);
  cout << "Thread b: Write process completed\n";
  cond_var.notify_one();
}

int main()
{
  thread t_read{read};
  thread t_write{write};

  t_read.join();
  t_write.join();

  return 0;
}