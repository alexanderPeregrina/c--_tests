#include <thread>
#include <iostream>
#include <future>

using namespace std;
using namespace std::literals;

void consumer(future<int>& fut)
{
  cout << "Waiting for result to complete\n";
  int result = fut.get();
  cout << "The result is " << result << endl; 
}

void producer(promise<int>& prom)
{
  this_thread::sleep_for(2s);
  cout << "Producing result\n";
  this_thread::sleep_for(5s);
  cout <<"Result completed\n";
  prom.set_value(42);
}

int main()
{
  promise<int> prom;
  future<int> fut = prom.get_future();
  thread t_producer{producer, ref(prom)};
  thread t_consumer{consumer, ref(fut)};

  t_consumer.join();
  t_producer.join();

  return 0;
}