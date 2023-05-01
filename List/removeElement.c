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

int removeElement(int* nums, int numsSize, int val)
{
	int i;
	int cur;

	cur = 0;
	for(i = 0; i < numsSize; i++)
	{
		if(nums[i] != val)
		{
			nums[cur] = nums[i];
			cur++;
		}
	}
	return cur;
}


int main(int argc, char* argv[])
{
	int	ret;
	int val;
	int numsSize;

	numsSize = sizeof(nums)/sizeof(int);
	val = atoi(argv[1]);
	printArray(nums, numsSize);

	ret = removeElement(nums, numsSize, val);
	printArray(nums, ret);
}
