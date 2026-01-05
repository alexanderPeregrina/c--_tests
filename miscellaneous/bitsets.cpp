#include <iostream>
#include <bitset>

using namespace std;

int main()
{
  bitset<8> my_bitset{0b01010101};

  cout << "The binary number is: " << my_bitset << endl;
  cout << "The binary number  (decimal) is: " << my_bitset.to_ulong() << endl;
  cout << "The binary number (string) is: " << my_bitset.to_string() << endl;

  for (int i = 0; i < my_bitset.size(); ++i)
  {
    cout << "The element "<< i+1 << " is " << my_bitset[i] << endl;
  }

  try
  {
    cout << "The 8th element is " << my_bitset.test(8) << endl;
  }
  catch(const std::exception& e)
  {
    std::cerr << e.what() << '\n';
  }

  // bitwise operations
  bitset<8> b1{0b10100101};
  bitset<8> b2{0xAA};
  
  cout << "b1 = " << b1 << endl;
  cout << "b2 = " << b2 << endl;
  cout << "~b1 = " << ~b1 << endl;
  cout << "b1 & b2 = " << (b1 & b2) << endl;
  cout << "b1 | b2 = " << (b1 | b2) << endl;
  cout << "b1 ^ b2 = " << (b1 ^ b2) << endl;
  cout << "b1 << 4 = " << (b1 << 4) << endl;
  cout << "b2 << 4 = " << (b2 << 4) << endl;
  cout << "b1 >> 4 = " << (b1 >> 4) << endl;
  cout << "b2 >> 4 = " << (b2 >> 4) << endl;

  // bit operations
  cout << "Current  value of b1" << b1 << endl;
  cout << "set all bits of b1" << b1.set() << endl;
  cout << "Reset all bits of b1" << b1.reset() << endl;
  cout << "Set 3rd bit of b1" << b1.set(3) << endl;
  cout << "Reset first bit of b1" << b1.reset(0) << endl;
  cout << "Invert all bits of b1" << b1.flip() << endl;
  cout << "Invert first bit of b1" << b1.flip(0) << endl;
  cout << "Current value of b1" << b1 << endl;
  
  return 0;
}