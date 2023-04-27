#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
   int               val;
   struct TreeNode   *left;
   struct TreeNode   *right;
}TreeNode_t;


int testArray[] = {3, 6, 9, 2, 4, 1};


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

int* inorderTraversal(TreeNode_t *root, int* returnSize)
{
   int ret;
   if(traversArry == NULL)
   {
      traversArry = malloc(20);
      traversArryIdx = 0;
   }
   if(root == NULL)
   {
      return NULL;
   }

   inorderTraversal(root->left, &ret);
   printf(" %d:%d -", traversArryIdx, root->val);
   traversArry[traversArryIdx++] = root->val;
   inorderTraversal(root->right, &ret);

   *returnSize = traversArryIdx;
   return traversArry;
}

int main(int argc, char *argv[])
{
   int i;
   int ret;
   TreeNode_t *root;

   root = NULL;
   for (i = 0; i < sizeof(testArray)/sizeof(int); i++)
   {
      root = insertTree(root, testArray[i]);
   }
   printf("\n");
   inorderTraversal(root, &ret);

   printf(" ::::: %d\n", ret);
}  