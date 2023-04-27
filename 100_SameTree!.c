#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct TreeNode {
   int               val;
   struct TreeNode   *left;
   struct TreeNode   *right;
}TreeNode_t;


int testArrayA[] = {5, 9, 1, 3, 7, 10};
int testArrayB[] = {5, 7, 1, 3, 9, 10};


TreeNode_t* createNode(int val)
{
   TreeNode_t * node = (TreeNode_t *)malloc(sizeof(TreeNode_t));
   node->val   = val;
   node->left  = NULL;
   node->right = NULL;

   return node;
}

TreeNode_t* insertTree(TreeNode_t *root, int val)
{
   if(root == NULL)
   {
      root = createNode(val);
      return root;
   }
   printf(" %d -", val);
   if(val < root->val)
   {
      root->left = insertTree(root->left, val);
   }else
   {
      root->right = insertTree(root->right, val);
   }

   return root;
}


int printArray(int *nums, int numsLen)
{
   int i;

   printf(" %d : ", numsLen);
   for(i = 0; i < numsLen; i++)
   {
      printf("%d, ", nums[i]);
   }
   printf("\n");
   return i;
}
int traversArryIdx;
int *traversArry;

bool isSameTree(TreeNode_t *p, TreeNode_t *q)
{
   bool ret;

   ret = true;
   if((p == NULL) && (q == NULL))
   {
      return true;
   }else if((p == NULL) || (q == NULL))
   {
      return false;
   }
   else
   {
      if(isSameTree(p->left, q->left) == false)
      {
         return false;
      }
      if(p->val != q->val)
      {
         return false;
      }
      if(isSameTree(p->right, q->right) == false)
      {
         return false;
      }
   }
   return true;
}

int main(int argc, char *argv[])
{
   int i;
   bool ret;
   TreeNode_t *testA;
   TreeNode_t *testB;

   testA = NULL;
   testB = NULL;
   for (i = 0; i < sizeof(testArrayA)/sizeof(int); i++)
   {
      testA = insertTree(testA, testArrayA[i]);
   }
   printf("\n");
   for (i = 0; i < sizeof(testArrayB)/sizeof(int); i++)
   {
      testB = insertTree(testB, testArrayB[i]);
   }
 
   ret = isSameTree(testA, testB);

   if(ret == true)
   {
      printf("\n identical - PASS\n");
   }else
   {
      printf("\n different - FAIL \n");
   }
}  