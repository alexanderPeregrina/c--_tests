#include <iostream>

using namespace std;

  namespace my_space
  {
    class Test
    {
      private:
        string name;
        int age;
      public:
        Test(const string& name, const int& age): name(name), age(age)
        {

        }

        void show()
        {
            cout << "Hello My name is " << name << ", I'm " << age << endl;
        }
    };
    Test t1{"Alex", 12};
  };

int main()
{
  my_space::Test t2{"Andres", 65};
  my_space::t1.show();
  t2.show();
  return 0;
}