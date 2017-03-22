#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include <string.h>

// restricting size of input
#define LEN 1000

int s[LEN][LEN], m[LEN][LEN];
bool inAResult[LEN];

void matrixChainOrder(int dims[], int length_dims) {
    int n = length_dims-1;

    for (int lenMinusOne = 1; lenMinusOne < n; lenMinusOne++) {
        for (int i = 0; i < n - lenMinusOne; i++) {
            int j = i + lenMinusOne;
            m[i][j] = INT_MAX;
            for (int k = i; k < j; k++) {
                int cost = m[i][k] + m[k+1][j] + dims[i]*dims[k+1]*dims[j+1];
                if (cost < m[i][j]) {
                    m[i][j] = cost;
                    s[i][j] = k;
                }
            }
        }
    }
}


void printOptimalParenthesizations(int i, int j) {
    if (i != j) {
        printOptimalParenthesizations(i, s[i][j]);
        printOptimalParenthesizations(s[i][j]+1, j);

        char istr[100], jstr[100];
        if(inAResult[i]) {
            strncpy(istr,"_result ", 100);
        }
        else {
            strncpy(istr," ", 100);;
        }

        if(inAResult[j]) {
            strncpy(jstr,"_result ", 100);
        }
        else {
            strncpy(jstr," ", 100);
        }

        printf(" A_%d%s* A_%d%s\n", i, istr, j, jstr);

        inAResult[i] = true;
        inAResult[j] = true;
    }
}

int main(int argc, char const *argv[])
{
    int dims[] = {20, 10, 5, 35, 45, 5, 10, 15};
    int length_dims = sizeof(dims)/sizeof(int);
    matrixChainOrder(dims, length_dims);
    
    printOptimalParenthesizations(0, length_dims-2);
    return 0;
}