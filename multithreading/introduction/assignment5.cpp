#include <iostream>
#include <thread>

using namespace std;

static int counter = 0;

void increment_counter()
{
  for (int i = 0; i <= 100000; ++i)
  {
    counter = i;
  }

  cout << "The count now is " << counter << endl;
}

int main()
{
  thread th1{increment_counter};
  thread th2{increment_counter};
  thread th3{increment_counter};
  thread th4{increment_counter};
  thread th5{increment_counter};
  thread th6{increment_counter};
  thread th7{increment_counter};
  thread th8{increment_counter};

  th1.join();
  th2.join();
  th3.join();
  th4.join();
  th5.join();
  th6.join();
  th7.join();
  th8.join();
  
  return 0;
}