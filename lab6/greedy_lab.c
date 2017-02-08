#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
Author: Manvendra Singh (@manu-chroma)

Problem Statement: 
Suppose you were to drive from point A to point B. 
Your gas tank with a capacity C, when full, holds enough gas to travel m miles. 
You have a precise map that gives distances between gas stations along the route. 
Let d1 < d2 < …. < dn be the locations of all the gas stations along the route where 
di is the distance from point A to the gas station. 

You can assume that the distance between neighboring gas stations is at most m miles.
In the case that the rate at which you can fill your tank at a gas station is r (in liters/minute), 
so if you stop to fill your tank from 2 liters to 8 liters, you would have to stop for 6/r minutes. 
Give the most efficient greedy solution, where you need to minimize the total time you stop for gas filling?
*/

void array_gen(int problem[], int no_of_stations, int m) {
	
	srand(time(NULL));
	// first station at 0 kms
	problem[0] = 0;
	for (int i = 1; i < no_of_stations; ++i)
	{
		problem[i] = (problem[i-1] + rand()%(m)+1);
	}
}

int main(int argc, char const *argv[])
{
	
	// getting input from the user to generate the dummy problem
	printf("enter the total distance of the trip\n");
	int total_distance = 100;
	scanf("%d", &total_distance);

	printf("enter the max distance between any two stations\n");
	int m = 20;
	scanf("%d", &m);

	printf("enter the max capacity of petrol tank\n");
	int capacity = 10; // in litres
	scanf("%d", &capacity);

	printf("enter the number of stations in between\n");
	int stations = 8;
	scanf("%d", &stations);

	printf("enter the rate of petrol fulfillment\n");
	int rate = 1;
	scanf("%d", &rate);

	/* 
	generating test case using the following constraint
	*/
	int problem[stations];
	array_gen(problem, stations, m);

	// make sure that total distance reaches max distance constraint
	// assuming generated Dab <= required Dab  
	if(problem[stations-1] < total_distance) {

		problem[stations-1] = total_distance;
		// loop through all the distances starting from the back 
		for (int i = stations-1; i > 0; i--)
		{
			// diff between last and second last
			int diff = problem[i] - problem[i-1];
			
			if(diff > m) {
				// need to shift previous station according to the constraint 
				problem[i-1] = problem[i] - m;
			}
			else {
			// we're done here.
				break;
			}	
		}
	}
	else {
		printf("test case invalid! try running program again\n");
		return 0;
	}

	// printing the test case data
	printf("test data is the following: \n");
	printf("total distance of the trip is %d\n", problem[stations-1]);
	for (int i = 0; i < stations; ++i)
	{
		printf("%d ", problem[i]);
	}
	printf("\n \n");

	// greedy algo to solve the problem 
	// start with full tank
	float distance_in_one_litre = (1.0*m/capacity), liters_for_one_kms = (1.0*capacity/m);

	float current_tank_capcity, ans;
	// init conditions
	current_tank_capcity = ans = 0;
	
	// printf("%f %f\n", distance_in_one_litre, liters_for_one_kms);
	for (int i = 1; i < stations; ++i)
	{	
		int distance_to_covered = problem[i] - problem[i-1];
		printf("distance_to_covered: %d\n", distance_to_covered);

		if(distance_to_covered > (current_tank_capcity*distance_in_one_litre)) {

			int remaining = distance_to_covered - (current_tank_capcity*distance_in_one_litre);
			// put something in tank 
			ans += (remaining*liters_for_one_kms);
			// make tank capacity to zero since all will be consumed when travelling to next
			current_tank_capcity = 0;
		}	
		else {
			// empty the tank for when arriving at next station 
			current_tank_capcity -= (distance_to_covered*liters_for_one_kms);
		}
	}

	printf("total litres of petrol filled at all stations: %f\n", ans);
	printf("final ans: %f\n", ans/rate);

	return 0;
}