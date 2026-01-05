#include <iostream>


#define NUM_COLS 3
#define NUM_ROWS 3
using namespace std;

int main ()
{
  
  int my_2d_array[NUM_ROWS][NUM_COLS]{1, 2, 3, 4, 5, 6, 7, 8, 9};
  int my_1d_array[]{1, 2, 3, 4, 5, 6, 7, 8, 9};
  
  for(int i = 0; i < NUM_ROWS; ++i)
  {
    for(int j = 0; j < NUM_COLS; ++j)
    {
      cout << my_2d_array[i][j] << " ";
    }
    cout << endl;
  }

  // using flattened array 
  for(int i = 0; i < NUM_ROWS; ++i)
  {
    for(int j = 0; j < NUM_COLS; ++j)
    {
      cout << my_1d_array[i * NUM_ROWS + j] << " ";
    }
  }
  cout << endl;

  return 0;
}
