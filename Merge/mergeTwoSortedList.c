#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LEN	10000

typedef struct ListNode {
	int 			val;
	struct ListNode *next;
} ListNode_t;
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
ListNode_t* mergeTwoLists(ListNode_t* list1, ListNode_t* list2)
{
	ListNode_t *head;
	ListNode_t *cur, *second;
	ListNode_t *tmp;

	if(list1->val < list2->val)
	{
		head 	= list1;
		cur 	= list1;
		second 	= list2;
	}else
	{
		head 	= list2;
		cur		= list2;
		second 	= list1; 
	}
	
	while(cur->next != NULL || second != NULL)
	{
		if(cur->next == NULL)
		{
			cur->next = second;
			break;
		}
		if(cur->next->val < second->val)
		{
			cur = cur->next;
		}else
		{
			tmp = second;
			second = cur->next;
			cur->next = tmp;
			cur = cur->next;
		}
	}
	return head;
}
int list1[] = {1, 2, 5, 6, 9, 10,1000};
int list2[] = {3, 4, 7, 8, 11, 12, 100, 9000};

ListNode_t listA[MAX_LEN];
ListNode_t listB[MAX_LEN];

int initializeList(ListNode_t *a, int *array, int size)
{
	int i;
	ListNode_t *old;
	for (i = 0; i < size; i++)
	{
		a->val = array[i];

//		printf("%d -> ", a->val);

		if(i == size-1)
		{
			a->next = NULL;
		}else
		{
			old = a;
			a++;
			old->next = a;
		}
	}
}

int printNode(ListNode_t *list)
{
	int i;
	i = 5;
	while(list != NULL)
	{
		printf("%d -> %x \n", list->val, list->next);
		list = list->next;
	}
	printf("\n");
}

int main(int argc, char* argv[])
{
	bool	ret;
	ListNode_t *head;
	initializeList(listA, list1, sizeof(list1)/sizeof(int));
	initializeList(listB, list2, sizeof(list2)/sizeof(int));
	printNode(listA);
	printNode(listB);

	head = mergeTwoLists(listA, listB);
	printNode(head);
}
