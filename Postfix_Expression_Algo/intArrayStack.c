/*
 * intArrayStack.c
 *
 *  Created on: Nov 20, 2016
 *      Author: inventor
 */
#include "intArrayStack.h"
#include <stdbool.h>

int int_array[INTSTACKSIZE];
int *int_array_ptr = &int_array[INTSTACKSIZE-1];
int int_pointer_counter = INTSTACKSIZE;

bool intStack_isEmpty()
{
	bool b = false;
	if(int_pointer_counter == INTSTACKSIZE)
	{
		b = true;
	}
	return b;
	}

bool intStack_isFull()
{
	bool b = false;
	if(int_pointer_counter == 0)
	{
		b = true;
	}
	return b;
	}

int intStack_peek()
{
	int data = 0;
	if(!intStack_isEmpty())
	{
		int_array_ptr++;
		data = *int_array_ptr;
		int_array_ptr--;
	}
	return data;
	}

bool intStack_push(int data)
{
	bool b = false;
	if(!intStack_isFull())
	{
		*int_array_ptr = data;
		int_array_ptr--;
		int_pointer_counter--;
		b = true;
	}
	return b;
	}

int intStack_pop()
{
	int data = 0;
	int_array_ptr++;
	int_pointer_counter++;
	data = *int_array_ptr;
	*int_array_ptr = 0;
	return data;
	}

int intStack_size()
{
	return INTSTACKSIZE - int_pointer_counter;
	}

