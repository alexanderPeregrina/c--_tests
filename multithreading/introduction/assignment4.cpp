#include <iostream>
#include <thread>
#include <vector>

using namespace std;

void fizzbuzz_generate_output(const string& name)
{
  static int count = 1;

  bool is_divisible_by_3 = (count % 3 == 0);
  bool is_divisible_by_5 = (count % 5 == 0);
  
  if ((is_divisible_by_3) && (is_divisible_by_5))
    cout << name <<" says fizzbuzz" << endl;
  else if (is_divisible_by_3)
    cout << name <<" says fizz" << endl;
  else if (is_divisible_by_5)
    cout << name << " says buzz" << endl;
  else
    cout << name << "says " << count << endl;

  count++;
}

void play_game()
{
  vector<string> players {"Abdul", "Bart", "Claudia", "Divya"};
  for(int i = 0; i < 10; ++i)
  {
    for(auto& it : players)
    {
      fizzbuzz_generate_output(it);
    }
  }
  
}
int main()
{
  cout <<"FizzBuzz Game\n";
  thread thr{play_game};

  for (int i = 0; i < 20 ; ++i)
    cout << "... Game is still playing\n";
  thr.join();
  return 0;
}