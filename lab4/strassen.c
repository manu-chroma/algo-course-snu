/*
Implementing Strassen Matrix Multiplication for 2x2 matrix
*/

#include <stdio.h>
#include <stdlib.h>

// util function to print 2-d array
void print_array(int a[][2]) {
	for (int i = 0; i < 2; ++i)
	{
		for (int j = 0; j < 2; ++j)
		{
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
}

// implementation of Strassen algorithm for 2x2 matrices
void multiply_mat(int a[][2], int b[][2], int c[][2]) {
	
	int p = (a[0][0]+a[1][1])*(b[0][0]+b[1][1]);
	int q = (a[1][0]+a[1][1])*b[0][0];
	int r = (a[0][0])*(b[0][1]-b[1][1]);
	int s = (a[1][1])*(b[1][0]-b[0][0]);
	int t = (a[0][0]+a[0][1])*b[1][1];
	int u = (a[1][0]-a[0][0])*(b[0][0]+b[0][1]);
	int v = (a[0][1]-a[1][1])*(b[1][0]+b[1][1]);

	c[0][0] = p+s-t+v;
	c[0][1] = r+t;
	c[1][0] = q+s;
	c[1][1] = p+r-q+u;

}

int main(int argc, char const *argv[])
{
	// input matrix
	int a[2][2] = {{1,2}, {3,4}};
	int b[2][2] = {{5,6}, {7,8}};
	// output matrix
	int c[2][2];

	// calling multiplication 
	multiply_mat(a, b, c);

	// pretty printing output 
	printf("multiplying matrix a\n");
	print_array(a);
	printf("and matrix b\n");
	print_array(b);
	printf("output matrix is: \n");
	print_array(c);

	return 0;
}