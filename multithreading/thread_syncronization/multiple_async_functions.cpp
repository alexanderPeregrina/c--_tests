#include <iostream>
#include <thread>
#include <future>

using namespace std;

unsigned long long fibonacci(unsigned long long n)
{
  if (n <= 1)
    return 1;
  else
    return fibonacci(n-1) + fibonacci(n-2);
}

int main()
{
  using namespace std::literals;
  cout << "Calculating the fibonacci of 44 and 48\n";
  future<unsigned long long> result1  =  async(launch::async, fibonacci, 44);
  future<unsigned long long> result2 = async(launch::async, fibonacci, 48);
  bool task1_finished = false;
  
  while(true)
  {
    cout << "Waiting for the result\n";
    if (result1.wait_for(500ms) == future_status::ready)
    { 
      cout << "Task1 has finished\n";   
      task1_finished = true;
      break;
    }
    else if(result2.wait_for(500ms) == future_status::ready)
    {
      cout << "Task2 has finished\n";
      break;
    }
  }

  if (task1_finished)
  {
    while (result2.wait_for(1s) != future_status::ready)
    { 
      cout << "Waiting for the results\n";
    }
  }
  else
  {
    while (result1.wait_for(1s) != future_status::ready)
    { 
      cout << "Waiting for the results\n";
    }
  }

  cout << "The final result is fib(44) = " << result1.get() << endl;
  cout << "The final result is fib(48) = " << result2.get() << endl;
 
}