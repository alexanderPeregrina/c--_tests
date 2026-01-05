#include <iostream>
#include <random>
#include <ctime>

using namespace std;
const int int_numbers_to_display = 10;
const int fp_numbers_to_display = 5;
const int max_int_value = 10;
const int min_int_value = 0;
const double max_double_value = 100.0f;
const double min_double_value = 0.0f;

// Provide a seed for the engine.. something that is constantly changing like time..
mt19937 mt_engine(static_cast<int>(time(nullptr)));
int main()
{
  uniform_int_distribution<int> uniform_int_dist(min_int_value, max_int_value);
  uniform_real_distribution<double> uniform_double_dist(min_double_value, max_double_value);

  for(int i = 0; i < int_numbers_to_display; ++i)
  {
    cout << "Integer random number: " << uniform_int_dist(mt_engine) << endl;
  }

  for(int i = 0; i < fp_numbers_to_display; ++i)
  {
    cout << "Double random number: "<< uniform_double_dist(mt_engine) << endl; 
  }
  return 0;
}