/*
 * example_codes.c
 *
 *  Created on: Jun 19, 2017
 *      Author: inventor
 */
#include <stdio.h>

int factorial(int n);

int main()
{
	printf("Hello World to University of Osun State\n");
	printf("%d\n", factorial(22));

	return 0;
	}

int factorial(int n)
{
	int i = 0;
	int prod = 1;
	int num = n;
	if(n == 1 || n == 0)
	{
		return 1;
	}
	else
	{
		for(i = 0; i < num; i++)
		{
			prod = prod * n;
			n = n - 1;
		}
		return prod;
	}
	}

//int pointer_factorial(int n)
//{
//
//	}



