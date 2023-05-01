#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LEN	10000

int nums[] = {1, 2, 3, 4, 5, 7, 8, 9, 10};

int printArray(int *num, int length)
{
	int i;
	for(i = 0; i < length; i++)
	{
		printf("%d ", num[i]);
	}
	printf("	: %d\n", length);
}


int searchInsert(int* num, int numsSize, int target){
	int i;
	int l, r;

	l = 0;
	r = numsSize -1;
	i = (l + r) / 2;

	while(l != r)
	{
		printf("%d \n", nums[i]);
		
		if (num[i] > target)
		{
			r = i - 1;
		}else if (num[i] < target)
		{
			l = i + 1;
		}else
		{
			break;
		}

		i = (l + r) / 2;

	}

	return i;
}

int main(int argc, char* argv[])
{
	int	ret;
	int val;
	int numsSize;
	int i;
	int target;

	target = atoi(argv[1]);

	numsSize = sizeof(nums)/sizeof(int);

	printArray(nums, numsSize);
	ret = searchInsert(nums, numsSize, target);
	
	printf("------ %d \n", ret);
}
