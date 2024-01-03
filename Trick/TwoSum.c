#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define TEST_IDX	10000
int tstNums[TEST_IDX];

void printArray(int *num, int l, int r)
{
	int i;
	for(i = l; i <= r; i++)
	{
		printf("%d, ", tstNums[i]);
	}
	printf("\n");
}

int initTstNums(int *num, int size)
{
	int i;

	for(i = 0; i < size; i++)
	{
		num[i] = rand() % (size*2);
	}
	printArray(num, 0, size - 1);
}

int verifySort(int *num, int size)
{
	int i;

	printArray(num, 0, size-1);

	for(i = 0; i < size-1; i++)
	{
		if(num[i] > num[i+1])
		{
			printf("Error! : Array is not in order at array[%d] : %d - %d", i, num[i], num[i+1]);
			break;
		}
	}
}

void swap(int* num, int a, int b)
{
	int tmp;
	tmp = num[a];
	num[a] = num[b];
	num[b] = tmp;
}

// Binary search
int bSearch(int *num, int numSize, int target)
{
	int 	idx, upper, lower;
	bool 	found;
	
	found 	= false;
	lower 	= 0;
	upper	= numSize - 1;
	idx 	= (lower + upper) / 2;

	while ((0 <= idx) && (idx < numSize))
	{
		if(num[idx] > target)
		{
			upper 	= idx - 1;
			idx 	= (lower + upper) / 2;
		}
		else if(num[idx] < target)
		{
			lower 	= idx + 1;
			idx 	= (lower + upper) / 2;
		}

		printf("num[%d] = %d : lower %d, upper %d\n", idx, num[idx], lower, upper);
		
		if(num[idx] == target)
		{
			found = true;
			break;
		}
		else if (lower == upper)
		{
			break;
		}
	
	}

	if(found == false)
	{
		idx = -1;
	}

	return idx;
}

// 3. //https://leetcode.com/problems/two-sum/
int twoSum(int* nums, int numSize, int target, int *index)
{
	int 	i;
	int 	l, r;
	bool 	bFound;

	l 		= 0;
	r 		= numSize - 1;
	bFound	= false;

	while(l < r)
	{
		if((nums[l] + nums[r]) == target)
		{
			bFound = true;
			index[0] = l;
			index[1] = r;
			break;
		}

		if((nums[l] + nums[r]) < target)
		{
			l++;
		}
		if((nums[l] + nums[r]) > target)
		{
			r--;
		}
	}
	return bFound;
}



int partition(int* num, int l, int r)
{
	int i, j;
	int p = r;
	int pivot = num[r];

	i = l - 1;
	for (j = l; j < r; j++)
	{
		if (num[j] < pivot)
		{
			i++;
			swap(num, i, j);
		}
	}

	swap(num, i + 1, p);
	p = i + 1;

	return p; 
}

int *quickSort(int* num, int l, int r)
{
	int p;
	if (l < r)
	{
		p = partition(num, l, r);
		{
			printf ("Left[%d]%d \n", p, tstNums[p]);
			printArray(tstNums, l, p-1);
			quickSort(num, l, p-1);
			printf ("Right[%d]%d \n", p, tstNums[p]);
			printArray(tstNums, p+1, r);
			quickSort(num, p+1, r);
		}
	}

}
int main(int argc, char* argv[])
{
	int a;
	int searchTarget;
	int numSize;
	int index[2];
	int ret;

	// Initialize
	numSize = atoi(argv[1]);
	searchTarget = atoi(argv[2]);
	if (numSize > TEST_IDX)
	{
		printf("invalid numSize! \n");
		return -1;
	}
	initTstNums(tstNums, numSize);

#if 1	
	// 1. quick sort
	quickSort(tstNums, 0, numSize - 1);
#endif
#if 0
	// error injection
	swap(tstNums, 15, 20);
#endif

#if 0
	// verify
	verifySort(tstNums, numSize);
#endif

#if 0
	// 2. bSearch
 	a = bSearch(tstNums, numSize, searchTarget);
 	printf("found %d at array[%d]=%d", searchTarget, a, tstNums[a]);
#endif

 	// 3. Twosum
	ret = twoSum(tstNums, numSize, searchTarget, index);
	if(ret == true)
	{
		printf("twosum of %d found num[%d]:%d + num[%d]:%d \n", searchTarget, index[0], tstNums[index[0]], index[1], tstNums[index[1]]);
	}
	else
	{
		printf("twosum of %d not found\n", searchTarget);
	}
}
