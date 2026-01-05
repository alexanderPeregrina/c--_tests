#include <future>
#include <thread>
#include <iostream>

using namespace std;

struct sum_struct
{
  int a;
  int b;
  int result;

  sum_struct()
  {
    a = 0;
    b = 0;
    result = 0;
  }

  sum_struct (int a, int b):
  a(a), b(b)
  {

  }
};


void producer(promise<sum_struct>& prom, sum_struct& values)
{
  using namespace std::literals;
  this_thread::sleep_for(2s);
  values.result = values.a + values.b;
  prom.set_value(values);
}

void consumer(future<sum_struct>& fut)
{
  cout << "Waiting for result\n";
  sum_struct sum_results = fut.get();
  cout << "The result of  "<< sum_results.a <<" + "<< sum_results.b << " = " << sum_results.result << endl;
}

int main()
{
  sum_struct sum_values {10, 47};
  promise<sum_struct> prom;
  future<sum_struct> results = prom.get_future();
  thread t_consumer{consumer, ref(results)};
  thread t_producer{producer, ref(prom), ref(sum_values)};

  t_producer.join();
  t_consumer.join();
  
  return 0;
}