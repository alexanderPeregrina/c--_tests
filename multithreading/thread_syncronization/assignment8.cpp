#include <mutex>
#include <iostream>
#include <thread>
#include <atomic>

class some_type {
public:
    some_type()
    {
      std::cout << "some_type constructor called\n";
    }

	void do_it() { /*...*/ }
};

std::atomic<some_type *> ptr{nullptr};            // Variable to be lazily initialized
std::mutex process_mutex;

void process() {
    if (!ptr) {                     // First check of ptr
        std::lock_guard<std::mutex> lk(process_mutex);
        
        if (!ptr)                  // Second check of ptr
            ptr = new some_type;   // Initialize ptr
    }
     some_type* p_some_type = ptr;
     p_some_type->do_it();
}

int main()
{
  std::thread t1(process);
  std::thread t2{process};

  t1.join();
  t2.join();

}