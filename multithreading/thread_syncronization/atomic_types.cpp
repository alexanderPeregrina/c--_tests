#include <iostream>
#include <atomic>
#include <thread>
#include <vector>

using namespace std;

// For integers constants and pointers no mutex are required, but the implementation is similar.. in performance.. 
atomic<int> x = 0;

void process()
{
    for(int i = 0; i < 100000; ++i)
    {
        ++x;
    }
}

int main()
{
  vector<thread> threads;

  for (int i = 0; i < 20; ++i)
  {
    threads.push_back(thread(process));
  }

  for (auto& it : threads)
  {
    it.join();
  }

  cout << "The value of X is: " << x << endl;
}