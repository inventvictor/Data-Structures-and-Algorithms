#include <stdio.h>
#include <stdbool.h>

void circularLinkedList_print();
bool circularLinkedList_isEmpty();
int circularLinkedList_length();
void circularLinkedList_insertFirst(int key, int data);
struct node* circularLinkedList_deleteFirst();

struct node* head = NULL;

struct node
{
	int key;
	int data;
	struct node* next;
	};

int main()
{
	circularLinkedList_insertFirst(0,0);
    circularLinkedList_insertFirst(1,45);
    circularLinkedList_insertFirst(2,56);
    circularLinkedList_insertFirst(6,98);
    circularLinkedList_print();
    printf("%d\n",circularLinkedList_length());
    struct node* deletedNode = circularLinkedList_deleteFirst();
    circularLinkedList_print();
    printf("%d\n",circularLinkedList_length());
    printf("%d, %d\n", deletedNode->key, deletedNode->data);
	return 0;
	}

void circularLinkedList_print()
{
	struct node* node_ptr = head;
	printf("[");
	while(node_ptr->next != node_ptr)
	{
		printf("(%d, %d)", node_ptr->key, node_ptr->data);
		node_ptr = node_ptr->next;
	}
	printf("]\n");
	}
bool circularLinkedList_isEmpty()
{
	struct node* node_ptr = head;
	bool b = false;
	if(node_ptr == NULL)
	{
		b = true;
	}
	return b;
	}

int circularLinkedList_length()
{
	int length = 0;
	struct node* node_ptr = head;
	while(node_ptr->next != node_ptr)
	{

		length++;
		node_ptr = node_ptr->next;
	}
	return length;
	}
void circularLinkedList_insertFirst(int key, int data)
{
	struct node* node_ptr = (struct node*)malloc(sizeof(struct node));
	node_ptr->key = key;
	node_ptr->data = data;
	if(circularLinkedList_isEmpty())
	{
		head = node_ptr;
		node_ptr->next = head;
	}
	else
	{
		node_ptr->next = head;
		head = node_ptr;
	}
	}

struct node* circularLinkedList_deleteFirst()
{
	struct node* node_ptr = head;
	head = node_ptr->next;
	node_ptr->next = NULL;
	return node_ptr;
	}
