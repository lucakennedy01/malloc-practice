#include <iostream>

#include <stdio.h>   
#include <stdlib.h> 

struct alignas(8) x_ {
  int q[4]; //size 16
  char a; //size 1  
  char b[2]; //size 2
}; //total size 19

int main(void)
{ 
  int *p1 = (int *)malloc(4*sizeof(int)); //allocates memory for a 4-wide array of int
  if (p1){
    for (int n=0; n<4; ++n) { //populate the array
      p1[n] = n*n;
      }
    for (int n=0; n<4; ++n) { //print allocated locations
      printf("p1[%d] location == %d\n", n, &p1[n]);
    }
    for (int n=0; n<4; ++n) { //print it back
      printf("p1[%d] == %d\n", n, p1[n]);
    }
    
  }

  free(p1);

  printf("\nAlignment of x_ == %i\n", alignof(struct x_));
    printf("Size of x_ == %i\n", sizeof(struct x_));
}

