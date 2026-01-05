#include <iostream>
#include <string>
#include <vector>
using namespace std;

template<class T>
T MAX(const T& t1, const T& t2)
{
  if (t1 > t2)
  {
    return t1;
  }
  return t2;
}
template<class T>
class Test
{
  private:
    T data;

  public:
  Test(const T& data): data(data)
  {
  }
  void show()
  {
    cout << "The value of data is: " << data <<endl;;
  }
  
};

int main ()
{
  const double& f1{10.25};
  const double& f2{15.23};

  auto f_max = MAX(f1, f2);

  cout << f_max << " is larger \n";

  Test<double> t1{f1};
  t1.show();

  Test<string> t2{"Hello"};
  t2.show();

  vector<Test<string>> vec_str{"Hello"s, "World"s};

  for (auto it : vec_str)
  {
    it.show();
  }

  return 0;
}