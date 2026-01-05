#include <iostream>

using namespace std;

class Shape
{
  public: 
    virtual void draw() const = 0;
};

class Circle : public Shape
{
  public:
    void draw() const override
    {
        cout <<"Drawing Circle\n";
    }
};

class Triangle : public Shape
{
  public:
    void draw() const override
    {
        cout <<"Drawing Triangle\n";
    }
};

int main()
{
  Circle circle;
  Triangle triangle;

  circle.draw();
  triangle.draw();
  return 0;
}

