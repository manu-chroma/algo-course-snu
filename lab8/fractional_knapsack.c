#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 100

struct item {
	double value, weight, density;
};

int compare(const void *s1, const void *s2)
{
  struct item *e1 = (struct item *)s1;
  struct item *e2 = (struct item *)s2;
  return e1->density - e2->density;
}

int main(int argc, char const *argv[])
{
	int no_of_items, capacity_of_knapsack;
	printf("enter the no of items and capacity of knapsack\n");
	scanf("%d", &no_of_items);
	scanf("%d", &capacity_of_knapsack);

	struct item list[MAX];
	for (int i = 0; i < no_of_items; ++i)
	{
		// x-> weight, y->value 
		int x, y;
		scanf("%d %d", &x,&y);
		list[i].value = (double)y;
		list[i].weight = (double)x;
		list[i].density = list[i].value/list[i].weight;
	}
	// sort the list in desending order
	qsort(list, no_of_items, sizeof(struct item), compare);

	printf("items in the knapsack: \n");
	// start from the end 
	int counter = no_of_items-1;
	double answer = 0, finish = 0;

	while(finish < (double)capacity_of_knapsack && counter >= 0) {
		printf("space left in bag: %f\n", capacity_of_knapsack- finish);

		// remaining weight that can be incorporated into the knapsack
		double remaining = (double)capacity_of_knapsack-finish;
		// extract full item or partially 
		double extracted_wt = fmin(list[counter].weight, remaining);
		if(remaining > list[counter].weight) {
			printf("taking complete item, capacity: %f weight: %f\n", list[counter].value, list[counter].weight);
		}
		else {
			printf("taking item partially, capacity: %f weight: %f\n", list[counter].value, list[counter].weight);
			printf("partial weight taken is: %f\n", extracted_wt);	
		}
		// add extracted_wt to global weight 
		finish += extracted_wt;
		// add value of item to the knapsack and increment answer
		answer += (list[counter].density*extracted_wt);
		// increment no_of_items counter
		counter--;
	}

	printf("total value of knapsack is: %f\n", answer);
	return 0;
}