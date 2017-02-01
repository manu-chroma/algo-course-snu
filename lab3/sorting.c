#include <stdio.h>
#include <stdlib.h>
#include <time.h> // to measure performance of the algo
#include <stdbool.h> // using bool functionality

#define max (int)1e8 // limit on size of array
#define MY_RAND_MAX (int)1e7 // limit on how large no can array store 

int unordered[max], arr[max]; // declaring array as global

// swap utility
void swap(int * a, int * b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void bubble_sort(int arr[], int size) {
	bool not_done = 1;

	while(not_done) {
		not_done = 0;
		for (int i = 0; i < size-1; ++i)
		{
			if(arr[i] > arr[i+1]) {
				swap(&arr[i], &arr[i+1]);
				not_done = 1;
			}
		}
	}
}

// counting_sort for implementing bubble sort
void count_sort(int arr[], int n, int exp)
{
    int output[n]; // output array
    int i, count[10] = {0};
 
    // count occurances of each digit at 10^exp place
    for (i = 0; i < n; i++)
        count[ (arr[i]/exp)%10 ]++;
 
    // Change count[i] so that count[i] now contains actual
    // position of the digit
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];
 
    // create output
    for (i = n - 1; i >= 0; i--)
    {
        output[count[(arr[i]/exp)%10] - 1] = arr[i];
        count[(arr[i]/exp)%10]--;
    }
 
    // copy back output to main
    for (i = 0; i < n; i++)
        arr[i] = output[i];
}

void radix_sort(int arr[], int size) {
	// find the max element in the array
	int m = arr[0];
	for (int i = 1; i < size; ++i)
	{
		if(m < arr[i])
			m = arr[i];
	}

	// call counting sort for each digit of the max_ element 
	for (int exp = 1; m/exp > 0; exp *= 10)
	{
		count_sort(arr, size, exp);
	}	
}

// merge utility function 
void merge(int arr[], int start, int mid, int end) {

	int size1 = mid-start+1, size2 = end-mid;
	int arr1[size1], arr2[size2];
	
	// copy contents of array into two seprate arrays
	for (int i = start, j = 0; i <= mid; ++i, ++j)
		arr1[j] = arr[i];

	for (int i = mid+1, j = 0; i <= end; ++i, ++j)
		arr2[j] = arr[i];

	// actual merging 
	int i, j, k;
	i = j = 0;
	k = start; 

	while(i < size1 && j < size2) {

		if(arr1[i] < arr2[j]) {
			arr[k] = arr1[i];
			i++;
			k++;
		}

		else {	
			arr[k] = arr2[j];
			j++;
			k++;
		}
	}

	// copy the remaining array from whichever array remains 
	for (; i < size1; ++i, ++k)
	{
		arr[k] = arr1[i];
	}

	for (; j < size2; ++j, ++k)
	{
		arr[k] = arr2[j];
	}
}

void mergesort(int arr[], int l, int r) {
	if(l < r) {

		int mid = (l+r)/2;

		mergesort(arr, l, mid);
		mergesort(arr, mid+1, r);
		merge(arr, l, mid, r);
	}
}

// utility function for printing array
int test_print(int arr[], int size) {
	for (int i = 0; i < size; ++i)
	{
		printf("%d\n", arr[i]);
	}
	printf("\n");
}


// helper function to initialise array before passing to sorting algo 
void init(int size) {
	
	// copy contents of unordered array into arr array
	for (int i = 0; i < size; ++i)
	{
		arr[i] = unordered[i];
	}
}

int main(int argc, char const *argv[])
{
	int n;
	printf("enter the size of the array: \n");
	scanf("%d", &n);

	srand(time(NULL)); // seed for random no. gen	
	// filling array with random numbers
	for (int i = 0; i < n; ++i)
		unordered[i] = rand()%MY_RAND_MAX;

	clock_t begin, end;

	init(n);
	begin = clock();
	bubble_sort(arr, n);
	end = clock();
	double time_bubble = (double)(end - begin) / CLOCKS_PER_SEC;

	init(n);
	begin = clock();
	mergesort(arr, 0, n-1);
	end = clock();
	double time_merge = (double)(end - begin) / CLOCKS_PER_SEC;

	init(n);
	begin = clock();
	radix_sort(arr, n);
	end = clock();
	double time_radix = (double)(end - begin) / CLOCKS_PER_SEC;

	printf("time taken for sorting algorithms\n");
	printf("mergesort: %f\n", time_merge);
	printf("bubble_sort: %f\n", time_bubble);
	printf("radix_sort: %f\n", time_radix);

	return 0;
}