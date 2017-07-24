/*
 * binary_search.c
 *
 *  Created on: Dec 17, 2016
 *      Author: inventor
 */

/*
 * mid = low + (high - low)/2
 * run-time complexity is O(log n)
 * The searched array must be sorted
 * */

#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#define ARRAY_SIZE 20

int array[ARRAY_SIZE] = {1,2,3,4,6,7,9,11,12,14,15,16,17,19,33,34,43,45,55,66};
int *array_ptr = array;

int midPoint = 0;
int highPoint = ARRAY_SIZE - 1;
int lowPoint = 0;
int comp_no = 0;

int *top_ptr = array;
int *bottom_ptr = array;
int size = ARRAY_SIZE;

int binary_search(int *array, int data);
void display_array(int *array_ptr, int size);


int main()
{
	//display_array(array_ptr, ARRAY_SIZE);
	if (binary_search(array_ptr, 45) == -1)
	{
		printf("Not Found");
	}
	return 0;
	}

void display_array(int *a_ptr, int size)
{
	int i = 0;
	printf("[");
	for(i = 0; i < size; i++)
	{
		printf("%d ", *a_ptr);
		a_ptr++;
	}
	printf("]\n");
	}

int binary_search(int *a_ptr, int data)
{
	int b = -1;
	while(lowPoint<=highPoint)
	{
		midPoint = lowPoint + (highPoint-lowPoint)/2;
		//midPoint = roundf(lowPoint + (highPoint-lowPoint)/2);
		a_ptr = &array[midPoint];
		bottom_ptr = &array[midPoint+1];
		top_ptr = &array[midPoint-((highPoint-lowPoint)/2)];
		if(*a_ptr < data)
		{
			comp_no++;
			printf("Comparison %d\n", comp_no);
			printf("upperbound: ");
			display_array(bottom_ptr, midPoint-lowPoint);
			lowPoint = midPoint + 1;
			b = -1;
		}
		else if(*a_ptr > data)
		{
			comp_no++;
			printf("Comparisons %d\n", comp_no);
			printf("lowerbound: ");
			display_array(top_ptr, highPoint-midPoint);
			highPoint = midPoint - 1;
			b = -1;
		}
		else
		{
			b = *a_ptr;
			printf("Total number of comparisons = %d\n", comp_no);
			printf("Found %d at index %ld\n", b, a_ptr-array);
			break;
		}
	}
	return b;
	}
