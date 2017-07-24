/*
 * linear_search.c
 *
 *  Created on: Dec 17, 2016
 *      Author: inventor
 */

/*
 * Run-time complexity = O(n)
 * */
#include <stdio.h>
#include <stdbool.h>
#define ARRAY_SIZE 20
int array[ARRAY_SIZE] = {1,2,3,4,6,7,9,11,12,14,15,16,17,19,33,34,43,45,55,66};
int *array_ptr = array;

int linear_search(int *array, int data);

int main()
{
	printf("Hello Victor");
	printf("Element at position %d\n", linear_search(array_ptr, 199));
	return 0;
	}

int linear_search(int *array, int data)
{
	int index = 1;
	while(*array != data && index < ARRAY_SIZE)
	{
		array++;
		index++;
	}
	if(index == ARRAY_SIZE)
	{
		index = -1;
	}
	return index;
	}
