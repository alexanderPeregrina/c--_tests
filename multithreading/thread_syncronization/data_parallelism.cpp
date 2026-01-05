#include <iostream>
#include <future>
#include <thread>
#include <random>
#include <vector>

using namespace std;
mt19937 mt_engine;

double get_sum(double* beg, double* last)
{
  return accumulate(beg, last, 0.0);
}

int main()
{
  vector<double> vec;
  uniform_real_distribution<double> d_distribution{0.0, 1.0};
  for (int i = 0; i < 1000000; ++i)
  {
    vec.push_back(d_distribution(mt_engine));
  }

  auto vec_size = vec.size();

  auto fut1 = async(launch::async, get_sum, &vec[0], &vec[0] + vec_size/4);
  auto fut2 = async(launch::async, get_sum, &vec[0] + vec_size /4, &vec[0] + vec_size/2);
  auto fut3 = async(launch::async, get_sum, &vec[0] + vec_size/2 , &vec[0] + (3 * vec_size) / 4);
  auto fut4 = async(launch::async, get_sum, &vec[0] + (3 * vec_size) / 4, &vec[0] + vec_size);

  // reduce step
  double result = fut1.get() + fut2.get() + fut3.get() + fut4.get();
  cout << "The sum of all random numbers is " << result << endl;

  return 0;
}