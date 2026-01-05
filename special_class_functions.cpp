#include <iostream>
#include <string> 
using namespace std;

class TestClass
{
  private:
    int number;
    string name
    ;

  public:
    // constructor
    TestClass(int number, const string& name)
    {
      cout << "Normal constructor used" << endl;
      this->number = number;
      this->name = name;
    }

    //copy constructor
    TestClass(const TestClass& other)
    {
      cout << "Copy constructor used" << endl;
      this->name = other.name;
      this->number = other.number;
    } 

    //assignment operator
    TestClass& operator=(const TestClass& other)
    {
      cout << "Assignment operator used" << endl;
      this->number = other.number;
      this->name = other.name;
      return *this;
    }

};
int main ()
{
  // Check all types of initializers
  string name = "Class A";
  TestClass object_a{1, name};
  TestClass object_b{object_a};
  TestClass object_c = TestClass(2, "Class C");
  object_b = object_c;
}