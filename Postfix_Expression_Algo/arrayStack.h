/*
 * arrayStack.h
 *
 *  Created on: Nov 18, 2016
 *      Author: inventor
 */
#include <stdio.h>
#include <stdbool.h>

#ifndef ARRAYSTACK_H_
#define ARRAYSTACK_H_

#define MAXSIZE 50
#define STACKSIZE 8

extern int ptr_counter;
extern char *arr_ptr;

bool stack_isEmpty();
bool stack_isFull();
char stack_peek();
bool stack_push(char data);
char stack_pop();
int stack_size();

#endif /* ARRAYSTACK_H_ */
