#include <thread>
#include <iostream>
#include <future>


using namespace std;
using namespace std::literals;

void consumer(shared_future<int>& fut)
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
  shared_future<int> fut1 = prom.get_future();
  shared_future<int> fut2 = fut1;
  thread t_producer{producer, ref(prom)};
  thread t_consumer1{consumer, ref(fut1)};
  thread t_consumer2{consumer, ref(fut2)};

  t_consumer1.join();
  t_consumer2.join();
  t_producer.join();

  return 0;
}