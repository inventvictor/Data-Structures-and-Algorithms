#include <stdio.h>
#include <stdbool.h>

#define MAXSIZE 8

int array[MAXSIZE];
int *array_ptr = &array[MAXSIZE-1];
int pointer_counter = MAXSIZE;

bool stack_isEmpty();
bool stack_isFull();
int stack_peek();
bool stack_push(int data);
int stack_pop();
int stack_size();

int main()
{
	int i = 0;
	stack_push(3);
	stack_push(4);
	stack_push(9585);
	stack_push(200);
	//stack_push(45);
	//stack_push(34);
	//stack_push(384);
	//stack_push(3435);
	for(i = 0; i < MAXSIZE; i++)
	{
		printf("%d\n", array[i]);
	}
//	printf("isFull-");
//	printf("%d\n", stack_isFull());
//	printf("%d\n", stack_peek());
	printf("Popped data - ");
	printf("%d\n", stack_pop());
	printf("Stack size - ");
	printf("%d\n", stack_size());
	stack_push(45895);
	stack_push(48936);
	for(i = 0; i < MAXSIZE; i++)
	{
		printf("%d\n", array[i]);
	}
	printf("Stack size - ");
	printf("%d\n", stack_size());
	return 0;
	}

bool stack_isEmpty()
{
	bool b = false;
	if(pointer_counter == MAXSIZE)
	{
		b = true;
	}
	return b;
	}

bool stack_isFull()
{
	bool b = false;
	if(pointer_counter == 0)
	{
		b = true;
	}
	return b;
	}

int stack_peek()
{
	int data = 0;
	if(!stack_isEmpty())
	{
		array_ptr++;
		data = *array_ptr;
		array_ptr--;
	}
	return data;
	}

bool stack_push(int data)
{
	bool b = false;
	if(!stack_isFull())
	{
		*array_ptr = data;
		array_ptr--;
		pointer_counter--;
		b = true;
	}
	return b;
	}

int stack_pop()
{
	int data = 0;
	array_ptr++;
	pointer_counter++;
	data = *array_ptr;
	*array_ptr = 0;
	return data;
	}

int stack_size()
{
	return MAXSIZE - pointer_counter;
	}
