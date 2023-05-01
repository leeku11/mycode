#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LEN	10000

int nums[] = {9, 9, 9, 9, 9};

int printArray(int *num, int length)
{
	int i;
	for(i = 0; i < length; i++)
	{
		printf("%d ", num[i]);
	}
	printf("	: %d\n", length);
}


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize){
 int *ret;
 int carry;
 int i;
 int retDigitsSize;

 carry = 0;

 for(i = digitsSize-1; i >= 0; i--)	// least significant to most
 {
 	if(digits[i] > 9)
 	{
 		printf("Wrong digits in array[%d], element must be a digit( < 9) \n", i);
 		free(ret);
 		return NULL;
 	}
 	digits[i] = digits[i] + carry + (i == (digitsSize-1));		// +1 + carry(if exist)

 	if(digits[i] > 9)
 	{
 		digits[i] -= 10;				// digit + carry 
 		carry = 1;
 	}else
 	{
 		carry = 0;						// no carry
 		break;
 	}
 }
 *returnSize = digitsSize + carry;

 ret = (int *)malloc(*returnSize * sizeof(int));

 if (carry)									// carry from most significant
 {
 	ret[0] = 1;
 }

 for(i = 0; i < *returnSize; i++)			// most significant to least
 { 
 	ret[i + carry] = digits[i];
 	//printf("ret[%d] = digits[%d]:%d\n", i+carry, i, digits[i]);

 }

 return ret;
}

int main(int argc, char* argv[])
{
	int	*ret;
	int retSize;
	int numsSize;
	int i;
	int target;

	numsSize = sizeof(nums);
	printArray(nums, numsSize / sizeof(int));
	ret = plusOne(nums, numsSize / sizeof(int), &retSize);
	printArray(ret, retSize);
	free(ret);
}
