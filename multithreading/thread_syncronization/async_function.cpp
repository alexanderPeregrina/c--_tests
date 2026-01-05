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
  cout << "Calculating the fibonacci of 44\n";
  future<unsigned long long> result = async(launch::async, fibonacci, 44);
  
  while(result.wait_for(1s) != future_status::ready)
  {
    cout << "Waiting for the result\n";
  }

  cout << "The final result is fib(44) = " << result.get() << endl;
  
}