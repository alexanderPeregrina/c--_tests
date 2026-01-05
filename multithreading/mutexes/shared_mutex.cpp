#include <iostream>
#include <mutex>
#include <thread>
#include <shared_mutex>
#include <vector>

using namespace std;
using namespace std::literals;

static int x = 0;
shared_mutex sh_mutex;

void write()
{
  lock_guard exclusive_lock{sh_mutex};
  //cout << "Increasing X, now the value of x is " << ++x << endl;
  this_thread::sleep_for(100ms);
}

void read()
{
  shared_lock sh_lock{sh_mutex};
  this_thread::sleep_for(10ms);
}

int main()
{

  vector<thread> threads;

    // write threads
  for(int i = 0; i < 5; ++i)
  {
    threads.push_back(thread(write));
  }

  // Read threads
  for (int i = 0; i < 100 ; ++i)
  {
    threads.push_back(thread(read));
  }



  for (auto& it : threads)
  {
    it.join();
  }

  cout << "The value of x is "<< x << endl;

}