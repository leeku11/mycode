#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LEN	10000

int nums[] = {1, 2, 3, 4, 5, 6, 6, 6, 6, 7, 7, 8, 8, 9, 10};

int printArray(int *num, int length)
{
	int i;
	for(i = 0; i < length; i++)
	{
		printf("%d ", num[i]);
	}
	printf("	: %d\n", length);
}

int removeDuplicates(int* nums, int numsSize)
{
	int i;
	int cur;

	cur = 0;
	for(i = 0; i < numsSize-1; i++)
	{
		if(nums[i] != nums[i+1])
		{
			cur++;
			nums[cur] = nums[i+1];
		}
	}
	return cur+1;
}


int main(int argc, char* argv[])
{
	int	ret;
	
	printArray(nums, sizeof(nums)/sizeof(int));

	ret = removeDuplicates(nums, sizeof(nums)/sizeof(int));
	printArray(nums, ret);
}
