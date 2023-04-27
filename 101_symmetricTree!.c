#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct TreeNode {
   int               val;
   struct TreeNode   *left;
   struct TreeNode   *right;
}TreeNode_t;


int testArrayA[] = {1, 2, 3};
int testArrayB[] = {1, 2, 3};


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

TreeNode_t* insertTreeReverse(TreeNode_t *root, int val)
{
   if(root == NULL)
   {
      root = createNode(val);
      return root;
   }
   printf(" %d -", val);
   if(val < root->val)
   {
      root->right = insertTree(root->right, val);
   }else
   {
      root->left = insertTree(root->left, val);
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





bool isMirrorTree(TreeNode_t *p, TreeNode_t *q)
{
   bool ret;

   ret = true;

   if((p == NULL) && (q == NULL))
   {
      printf(" p == q == NULL \n");
      return true;
   }else if((p == NULL) || (q == NULL))
   {
      if(p != NULL)
      {
         printf("p->val = %d", p->val);
      }   
      if(q != NULL)
      {
         printf("q->val = %d", q->val);
      }
      return false;
   }
   else
   {
      printf("left : %d == right : %d \n", p->val, q->val);
      if(isMirrorTree(p->left, q->right) == false)
      {
         return false;
      }
      if(p->val != q->val)
      {
         return false;
      }
      if(isMirrorTree(p->right, q->left) == false)
      {
         return false;
      }
   }
   return true;
}

bool isSymmetric(TreeNode_t *root)
{
   if(root == NULL)
   {
      return true;
   }else
   {
      return isMirrorTree(root->left, root->right);
   }
}

int main(int argc, char *argv[])
{
   int i;
   bool ret;
   TreeNode_t *testA;
   TreeNode_t *testB;
   TreeNode_t root;

   testA = NULL;
   testB = NULL;
   for (i = 0; i < sizeof(testArrayA)/sizeof(int); i++)
   {
      testA = insertTree(testA, testArrayA[i]);
   }
   printf("\n");
   for (i = 0; i < sizeof(testArrayB)/sizeof(int); i++)
   {
      testB = insertTreeReverse(testB, testArrayB[i]);
   }
   printf("\n");
   
   root.val = 100;
   root.left = testA;
   root.right = testB;

   ret = isSymmetric(&root);

   if(ret == true)
   {
      printf("\n symmetric - PASS\n");
   }else
   {
      printf("\n asymmetric - FAIL \n");
   }
}  