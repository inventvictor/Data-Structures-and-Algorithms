/*
 * intArrayStack.h
 *
 *  Created on: Nov 20, 2016
 *      Author: inventor
 */
#include <stdbool.h>
#include <stdio.h>

#ifndef INTARRAYSTACK_H_
#define INTARRAYSTACK_H_

#define INTSTACKSIZE 8

bool intStack_isEmpty();
bool intStack_isFull();
int intStack_peek();
bool intStack_push(int data);
int intStack_pop();
int intStack_size();


#endif /* INTARRAYSTACK_H_ */
