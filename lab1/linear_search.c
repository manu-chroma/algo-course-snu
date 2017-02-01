#include <stdio.h>
#include <time.h> // to measure performance of the algo

// macros
#define MAX (int)1e6
#define n (int)1e6

/*
linear search function
params: array, key to be searched, size of the array
returns 1: if KEY is found
returns 0: if KEY not found
*/
int linear_search(int arr[], int key, int size) {
    for (int i =0; i < size; i++) {
        if(arr[i] == key)
            return 1; 
    }
    return 0;
}

void generic_create_file() {
    // generic function to create linear search input file 
    
    FILE* fp;
    fp = fopen("create_file.txt", "w");

    // write 1000000 elements according to the requirements, using rand()%num
    for(int i = 0; i < MAX; i++) {
        fprintf(fp, "%d ", (rand()%1000));
    }
}

int main() {
    // declaring array of size 10^6
    int arr[MAX];

    // opening file for reading input
    FILE *f;
    f = fopen("increasing_elements.txt", "r");

    for(int i = 0; i < n; i++) {
        // scanf("%d", &arr[i]);
        fscanf(f, "%d ", &arr[i]);
    }

    printf("enter the value of key to be searched: ");
    int key;
    scanf("%d", &key);

    // for measuring linear search runtime 
    clock_t begin = clock();

    if(linear_search(arr, key, n)) {
        printf("key found! \n");
    }
    else {
        printf("key not found \n");
    }

    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("time taken for linear search %f \n", time_spent);

    return 0;
}