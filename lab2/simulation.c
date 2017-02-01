#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define max 1000

int main() {
    int n;
    printf("enter value of n: ");
    scanf("%d", &n);
    int m = ceil(log2(n));
    // seed for random no. generator 
    srand(time(NULL));
    
    // declare array to store freq of each occurrance
    int freq[max] = {0};
    
    for(int i = 0; i < max; ) {
      // generate number of n bits 
      char num[m];
      for(int j = 0; j < m; j++) {
          num[j] = random()%2 + '0';
      }  
      // convert to decimal number
      int num_gen = (int)strtol(num, NULL, 2);
      freq[num_gen]++;
      if(num_gen < n) {
          i++;
      }
    }

    // printing the nos in range [1,n]
    // mapping rand number generated to (0,n-1) because of mod limitations 
    double sum = 0;
    for(int i = 0; i < n; i++) {
        printf("freq of %d is: %f \n", i+1, 1.0*freq[i]/max);
    }
    return 0;
}