#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 10000

// generic swap macro
#define swap(x,y) do {   \
   typeof(x) _x = x;     \
   typeof(y) _y = y;     \
   x = _y;               \
   y = _x;               \
 } while(0)

/*
author: Manvendra Singh
github.com/manu-chroma
*/

// functions definitions
void siftdown(int arr[], int start, int end);
void heapify(int arr[], int length);
void heapsort(int arr[], int length);

/*
(Put elements of 'a' in heap order, in-place)
procedure heapify(a, count) is
    (start is assigned the index in 'a' of the last parent node)
    (the last element in a 0-based array is at index count-1; find the parent of that element)
    start ← iParent(count-1)
    
    while start ≥ 0 do
        (sift down the node at index 'start' to the proper place such that all nodes below
         the start index are in heap order)
        siftDown(a, start, count - 1)
        (go to the next parent node)
        start ← start - 1
    (after sifting down the root all nodes/elements are in heap order)
*/
int iParent(int a) {
	return floor((a-1)/2);
}

void heapify(int arr[], int length) {

	// start with the last parent node
	int start = iParent(length-1);
	for (; start >= 0; start--) 
	{
		siftdown(arr, start, length-1);
	}
}

/*
(Repair the heap whose root element is at index 'start', assuming the heaps rooted at its children are valid)
procedure siftDown(a, start, end) is
    root ← start

    while iLeftChild(root) ≤ end do    (While the root has at least one child)
        child ← iLeftChild(root)   (Left child of root)
        swap ← root                (Keeps track of child to swap with)

        if a[swap] < a[child]
            swap ← child
        (If there is a right child and that child is greater)
        if child+1 ≤ end and a[swap] < a[child+1]
            swap ← child + 1
        if swap = root
            (The root holds the largest element. Since we assume the heaps rooted at the
             children are valid, this means that we are done.)
            return
        else
            swap(a[root], a[swap])
            root ← swap            (repeat to continue sifting down the child now)
*/
int iLeftChild(int root) {
	return 2*root+1;
}

void siftdown(int arr[], int start, int end) {
	int root = start;

	while(iLeftChild(root) <= end) {
		int child = iLeftChild(root);
		int swap_ = root;

		if(arr[swap_] < arr[child]) {
			swap_ = child;
		}

		if(child+1 <= end && arr[swap_] < arr[child+1]) {
			swap_ = child+1;
		}

		if(swap_ == root) {
			return;
		}
		else {
			swap(arr[root], arr[swap_]);
			root = swap_;
		}
	}
}

/*
procedure heapsort(a, count) is
    input: an unordered array a of length count
 
    (Build the heap in array a so that largest value is at the root)
    heapify(a, count)

    (The following loop maintains the invariants that a[0:end] is a heap and every element
     beyond end is greater than everything before it (so a[end:count] is in sorted order))
    end ← count - 1
    while end > 0 do
        (a[0] is the root and largest value. The swap moves it in front of the sorted elements.)
        swap(a[end], a[0])
        (the heap size is reduced by one)
        end ← end - 1
        (the swap ruined the heap property, so restore it)
        siftDown(a, 0, end)
*/

void heapsort(int arr[], int length) {
	// heapify procedure to create heap
	// using zero-based indices
	heapify(arr, length);

	int end = length-1;
	for (; end > 0; )
	{
		swap(arr[end], arr[0]);
		end--;

		siftdown(arr, 0, end);
	}
}

int main(int argc, char const *argv[])
{
	int arr[N];
	int n;
	
	printf("enter the number to be sorted\n");
	scanf("%d", &n);
	// generate random numbers to sort
	for (int i = 0; i < n; ++i)
	{
		arr[i] = rand()%1000;
	}
	printf("unsorted arrry: \n");
	for (int i = 0; i < n; ++i)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	printf("\n");

	//sort the numbers
	heapsort(arr, n);
	printf("sorted array:\n");
	// print the numbers
	for (int i = n-1; i >= 0; i--)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");

	return 0;
}