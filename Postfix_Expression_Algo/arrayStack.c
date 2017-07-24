/*
 * arrayStack.c
 *
 *  Created on: Nov 18, 2016
 *      Author: inventor
 */

#include "arrayStack.h"
#include <stdbool.h>

char array[STACKSIZE];
char *arr_ptr = &array[STACKSIZE-1];
int ptr_counter = STACKSIZE;

bool stack_isEmpty()
{
	bool b = false;
	if(ptr_counter == STACKSIZE)
	{
		b = true;
	}
	return b;
	}

bool stack_isFull()
{
	bool b = false;
	if(ptr_counter == 0)
	{
		b = true;
	}
	return b;
	}

char stack_peek()
{
	char data;
	if(!stack_isEmpty())
	{
		arr_ptr++;
		data = *arr_ptr;
		arr_ptr--;
	}
	return data;
	}

bool stack_push(char data)
{
	bool b = false;
	if(!stack_isFull())
	{
		*arr_ptr = data;
		arr_ptr--;
		ptr_counter--;
		b = true;
	}
	return b;
	}

char stack_pop()
{
	char data;
	arr_ptr++;
	ptr_counter++;
	data = *arr_ptr;
	*arr_ptr = 0;
	return data;
	}

int stack_size()
{
	return STACKSIZE - ptr_counter;
	}
