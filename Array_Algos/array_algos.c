#include <stdio.h>

#define ARRAY_LENGTH 9
int array[ARRAY_LENGTH] = {16,12,4,5,6,1,3,5,6};

/*
 * Author - Invent Victor
 * Notes - Arrays Algorithms */

////Arrays////
int insertAtBeginning(int val, int *array, int length);
int insertAtAGivenIndex(int val, int index, int *array, int length);
int insertAtEnd(int val, int *array, int length);
int insertAfterGivenIndex(int val, int index, int *array, int length);
int insertBeforeGivenIndex(int val, int index, int *array, int length);
int deleteAtGivenIndex(int index, int *array, int length);
int searchValue(int val, int *array, int length);
void updateValueAtIndex(int val, int index, int *array, int length);

int main()
{
	int i = 0, n = ARRAY_LENGTH;
	n = insertAtBeginning(56, array, n);
	n = insertAtAGivenIndex(100, 3, array, n);
	for (i = 0; i<n; i++)
		{
			printf("array[%d] - %d\n", i , array[i]);
		}
//	n = insertAtEnd(200, array, n);
//	n = insertAfterGivenIndex(350, 8, array, n);
//	n = insertAfterGivenIndex(750, 10, array, n);
//	printf("Length is %d\n", n);
//	n = deleteAtGivenIndex(13, array, n);
//    n = insertBeforeGivenIndex(786, 3, array, n);
//	int indx = searchValue(751, array, n);
//	printf("Found %d at index %d \n", 751, indx);
//	updateValueAtIndex(79, 7, array, n);
//	for (i = 0; i<n; i++)
//	{
//		printf("array[%d] - %d\n", i , array[i]);
//	}
//	indx = searchValue(750, array, n);
//	printf("Found %d at index %d \n", 750, indx);
	return 0;
	}

int length(int *array)
{
	return 0;
	}

int insertAtBeginning(int val, int *array, int length)
{


	//****Using Array indexing****//
//	int j = length;
//	while(j != 0)
//	{
//		array[j] = array[j-1];
//		j = j - 1;
//	}
//	array[j] = val;
//	int new_length = length + 1;
//	return new_length;


	//****Using Two Pointers****//
//	int j = 0;
//	int *array_ptr_1 = &array[length-1];
//	int *array_ptr_2 = &array[length];
//	while(j < length-1)
//	{
//		int d = *array_ptr_1;
//		*array_ptr_2 = d;
//		array_ptr_1--;
//		array_ptr_2--;
//		j++;
//	}
//	int p = *array_ptr_1;
//	*array_ptr_1 = val;
//	*array_ptr_2 = p;
//	return length+1;


	//****Using One Pointer****//
	int j = 0;
	int *array_ptr = &array[length-1];
	while(j < length)
	{
		int d = *array_ptr;
		array_ptr++;
		*array_ptr = d;
		array_ptr -= 2;
		j++;
	}
	array_ptr = &array[0];
	*array_ptr = val;
	return length+1;
	}

int insertAtAGivenIndex(int val, int index, int *array, int length)
{
	//****Using Array Indexing***//
//	int j = length;
//	while (j != index)
//	{
//		array[j] = array[j - 1];
//		j = j - 1;
//	}
//	array[j] = val;
//	int new_length = length + 1;
//	return new_length;

	//****Using One Pointer***//
	int movem = 0;
	int *array_ptr = &array[length-1];
	while(array_ptr != &array[index])
	{
		int d = *array_ptr;
		array_ptr++;
		*array_ptr = d;
		array_ptr -= 2;
		movem++;
	}
	int d = *array_ptr;
	array_ptr++;
	*array_ptr = d;
	array_ptr--;
	*array_ptr = val;
	return length+1;
	}

int insertAtEnd(int val, int *array, int length)
{

	//***USing Array Indexing****//
//	array[length] = val;
//	int new_length = length + 1;
//	return new_length;

	//***Using One Pointer****//
	int *array_ptr = &array[length-1];
	array_ptr++;
	*array_ptr = val;
	return length+1;
	}

int insertAfterGivenIndex(int val, int index, int *array, int length)
{

	//****Using Array Indexing****//
//	int j = length;
//	while (j != index+1)
//	{
//		array[j] = array[j-1];
//		j = j - 1;
//	}
//	array[j] = val;
//	int new_length = length + 1;
//	return new_length;

	//****Using One Pointer****//
	int movem = 0;
	int *array_ptr = &array[length-1];
	while(array_ptr != &array[index])
	{
		int d = *array_ptr;
		array_ptr++;
		*array_ptr = d;
		array_ptr -= 2;
		movem++;
	}
	array_ptr++;
	*array_ptr = val;
	return length+1;
	}

int insertBeforeGivenIndex(int val, int index, int *array, int length)
{
	//****Using Array Indexing****//
//	int j = length;
//	while (j != index-1)
//	{
//		array[j] = array[j-1];
//		j = j-1;
//	}
//	array[j] = val;
//	int new_length = length + 1;
//	return new_length;

	//****Using One Pointer***//
	int movem = 0;
	int *array_ptr = &array[length-1];
	while(array_ptr != &array[index-1])
	{
		int d = *array_ptr;
		array_ptr++;
		*array_ptr = d;
		array_ptr -= 2;
		movem++;
	}
	int d = *array_ptr;
	array_ptr++;
	*array_ptr = d;
	array_ptr--;
	*array_ptr = val;
	return length+1;
	}

int deleteAtGivenIndex(int index, int *array, int length)
{
	//****Using Array Indexing****//
//	int j = length;
//	while (index != (j-1))
//	{
//		array[index] = array[index+1];
//		index += 1;
//	}
//	array[index] = 0;
//	int new_length = length - 1;
//	return new_length;

	//****Using One Pointer****//
	int *array_ptr = &array[index];
	while(index != (length-1))
	{
		array_ptr++;
		int d = *array_ptr;
		array_ptr--;
		*array_ptr = d;
		array_ptr++;
		index+=1;
	}
	return length-1;
	}

int searchValue(int val, int *array, int length)
{
	//****Using Array Indexing****//
//	int j = length;
//	while(array[j] != val && j >= 0)
//	{
//		j = j - 1;
//	}
//	return j;

	//****Using one Pointer****//
	int *array_ptr = &array[length];
	int j = length;
	while(*array_ptr != val && j>=0)
	{
		array_ptr--;
		j--;
	}
	return j;
	}

void updateValueAtIndex(int val, int index, int *array, int length)
{
	//****Using Array Indexing****//
//	if (index >= 0 && index <= length)
//	{
//		array[index] = val;
//	}

	//****Using One Pointer****//
	int *array_ptr = array;
	*(array_ptr+index) = val;
	}
