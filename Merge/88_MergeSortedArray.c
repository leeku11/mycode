#include <stdio.h>
#include <stdlib.h>

int nums1[] = {0};
int nums2[] = {1};


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

void merge(int *nums1, int *nums2, int m, int n)
{
   int readNum1, readNum2;
   int writeNum1;             // will write to nums1


   readNum1 = m - 1;
   readNum2 = n - 1;
   writeNum1 = m + n -1;      // will insert from end of nums1 with biggest num

   while(readNum2 >= 0)
   {
      //printf("%d %d -> %d \n", readNum1, readNum2, writeNum1);

      if(nums1[readNum1] > nums2[readNum2])
      {
         nums1[writeNum1] = nums1[readNum1];
         readNum1--;
      }else
      {
         nums1[writeNum1] = nums2[readNum2];
         readNum2--;         
      }
      writeNum1--;
      //printArray(nums1, m+n);
   }
}

int main(int argc, char *argv[])
{
   printArray(nums1, sizeof(nums1)/sizeof(int));
   printArray(nums2, sizeof(nums2)/sizeof(int));

   merge(nums1, nums2, sizeof(nums1)/sizeof(int)-sizeof(nums2)/sizeof(int),sizeof(nums2)/sizeof(int));
   printArray(nums1, sizeof(nums1)/sizeof(int));

}