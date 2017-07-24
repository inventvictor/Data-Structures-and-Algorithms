/*
 * bubble_sort.c
 *
 *  Created on: Dec 21, 2016
 *      Author: inventor
 */

/*
 * Bubble Sort is a simple sorting algorithm. This sorting algo,
 * is comparison-based in which each pair of adjacent elements is
 * compared and the elements are swapped if they are not in order.
 * This algo is not suitable for large data sets as its average and
 * worst case complexity are of O(n^2) where n is the number of items.
 * */
#include <stdio.h>
#include <stdbool.h>

#define ARRAYSIZE 10

int array[ARRAYSIZE] = {1,8,4,6,0,3,5,2,7,9};
int *array_ptr = array;

void swap(int *a_ptr, int *b_ptr);
void bubble_sort(int arr[]);
void printSortedArray(int arr[]);

int main()
{
	printSortedArray(array_ptr);
	bubble_sort(array_ptr);
	printSortedArray(array_ptr);
	return 0;
	}

void printSortedArray(int arr[])
{
	int i = 0;
	printf("[");
	for(i = 0; i < ARRAYSIZE; i++)
	{
		printf(" %d ", arr[i]);
	}
	printf("]\n");
	}

void swap(int *a_ptr, int *b_ptr)
{
	int c = *a_ptr;
	*a_ptr = *b_ptr;
	*b_ptr = c;
	}

void bubble_sort(int arr[])
{
	int i = 0, j = 0;
	for(i = 0; i < ARRAYSIZE; i++)
	{
		for(j = 0; j < ARRAYSIZE; j++)
		{
			int n = j+1;
			if (arr[j] > arr[n] && n < ARRAYSIZE)
			{
				swap(&arr[j], &arr[n]);
			}
		}
	}
	}
