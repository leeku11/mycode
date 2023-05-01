#include <stdio.h>
#include <stdlib.h>

// Sqrt(999999999) = 31622

#define MAX_NUM   100
typedef struct ListNode{
  int val;
  struct ListNode *next;
} ListNode_t;

int testArray[] = {1, 1, 2, 3, 3};

int initList(ListNode_t *list, int *a, int len)
{
  int i;
  ListNode_t *prv;
  for(i = 0; i < len; i++)
  {

    list->val = a[i];

    prv = list;
    list++;
    prv->next = list;
        
    printf("%x [%d, %x]\n",prv, prv->val, prv->next);


  }
  list[i-1].next = NULL;
  printf("len = %d\n", len);
  return 0;
}

int printNode(ListNode_t *head)
{
  int max;
  ListNode_t *cur;
  cur = head;
  max = 0xFFFFFFFF;   // guard
  while((max--) && cur->next != NULL)
  {
    printf("%x:%d\n",(int)cur, cur->val);
    cur = cur->next;
  }
  printf("\n");
  return 0;
}


ListNode_t* deleteDuplicates(ListNode_t *head)
{
  ListNode_t *cur;
  cur = head;
  int val;

  while(cur->next != NULL)
  {
    if(cur->val == cur->next->val)
    {
      cur->next = cur->next->next;
    }else
    {
      cur = cur->next;
    }

  }

  return head;
}

int main(int argc, char *argv[])
{
   int a;
   ListNode_t *ret;
   ListNode_t *head;

   head = malloc(sizeof(ListNode_t) * MAX_NUM);



   initList(head, testArray, sizeof(testArray)/sizeof(int));
   printNode(head);
    ret = deleteDuplicates(head);
   printNode(ret);

   free(head);
   return 0;
}