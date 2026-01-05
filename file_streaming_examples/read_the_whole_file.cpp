#include <iostream>
#include <fstream>

using namespace std;

int main ()
{
  ifstream ifile{"example.txt", ios::binary | ios::ate}; //open the file at the end of file character
  auto size = ifile.tellg(); // get the current position for read: eof
  ifile.seekg(0, ios::beg); // back to the beginning of the file

  cout << "Size of file is: " << size << endl;
  char* buffer = new char[size];

  ifile.read(buffer, size);
  for (int i = 0; i < size; i++)
  {
    cout << buffer[i];
  }
  cout << endl; 
  ifile.close();
  return 0;
}