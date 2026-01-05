#include <stdio.h>
#include "array.h"

void print_array(int array[], int n)
{
int i;
  for (i = 0; i < n; ++i)
  {
    printf("Array element %d: %d\n", i, array[i]);
  } 
}

