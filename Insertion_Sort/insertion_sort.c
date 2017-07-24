/*
 * insertion_sort.c
 *
 *  Created on: Dec 22, 2016
 *      Author: inventor
 */
/*
 * This is an in-place comparison-based sorting algo. Here, a
 * sub-list is maintained which is always sorted
 * The array is searched sequentially and unsorted items are
 * moved and inserted into the sorted sub-list(in the same array).
 * This algo is not suitabe for large data sets as its average and
 * worst case complexity are of O(n^2), where n is the number of
 * items.
 * */

#include <stdio.h>
#include <stdbool.h>

#define ARRAYSIZE 8
int array[ARRAYSIZE] = {14,33,27,10,35,19,42,45};

void printSortedArray(int arr[]);
void swap(int *a_ptr, int *b_ptr);
void insertion_sort(int a[]);

int main()
{
	printSortedArray(array);
	insertion_sort(array);
	printSortedArray(array);
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

void insertion_sort(int a[])
{
	int i = 0;
	for(i = 0; i < ARRAYSIZE; i++)
	{
		int n = i+1;
		if(a[i] > a[n] && n < ARRAYSIZE)
		{
			swap(&a[i], &a[n]);
			int q = i;
			int m = q-1;
			while(a[q] < a[m] && m >= 0)
			{
				swap(&a[q], &a[m]);
				q--;
				m--;
				if(q <= 0)
				{
					q = 1;
					m = q-1;
				}
			}
		}
	}
	}
