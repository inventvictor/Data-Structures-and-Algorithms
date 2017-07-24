/*
 * hash_table.c
 *
 *  Created on: Dec 20, 2016
 *      Author: inventor
 */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define ARRAYSIZE 20

int hashCode(int key);
void insertData(int key, int value);
struct dataItem *search(int key);
void delete(struct dataItem *item);
void printHashTable();

struct dataItem
{
	int key;
	int value;
	};
struct dataItem *hashArray[ARRAYSIZE] = {};

int main()
{
	insertData(1, 20);
	insertData(2, 70);
	insertData(42, 80);
	insertData(4, 25);
	insertData(12, 44);
	printHashTable();
	struct dataItem *searchedItem = search(42);
	if(searchedItem == NULL)
	{
		printf("Not found\n");
	}
	else
	{
		printf("Search results = (%d, %d)\n", searchedItem->key, searchedItem->value);
	}
	delete(searchedItem);
	printHashTable();
	return 0;
	}

int hashCode(int key)
{
	return key % ARRAYSIZE;
	}

void insertData(int key, int value)
{
	struct dataItem *item = (struct dataItem *)malloc(sizeof(struct dataItem));
	item->key = key;
	item->value = value;
	int hash = hashCode(key);
	//Linear Probing
	while(hashArray[hash] != NULL && hashArray[hash]->key != key)
	{
		hash++;
		hash = hashCode(hash);
	}
	hashArray[hash] = item;
	}

struct dataItem *search(int key)
{
	int hash = hashCode(key);
	//Linear Probing
	while(hashArray[hash] != NULL && hashArray[hash]->key != key)
	{
		hash++;
		hash = hashCode(hash);
	}
	return hashArray[hash];
	}

void delete(struct dataItem *item)
{
	int hash = hashCode(item->key);
	//Linear Probing
	while(hashArray[hash] != NULL && hashArray[hash]->key != item->key)
	{
		hash++;
		hash = hashCode(hash);
	}
	hashArray[hash] = NULL;
	}


void printHashTable()
{
	int i = 0;
	for(i = 0; i < ARRAYSIZE; i++)
	{
		if(hashArray[i] == NULL)
		{
			printf(" ~~ ");
		}
		else
		{
			printf("(%d, %d)", hashArray[i]->key, hashArray[i]->value);
		}
	}
	printf("\n");
	}

