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

int strStr(char * haystack, char * needle){
	int		position;
	int 	i, j;

	position 		= -1;
	i 				= 0;
	j				= 0;

	while (haystack[i] != '\0')
	{
		if(needle[j] == '\0')
		{
			break;
		}

		if(haystack[i] == needle[j])
		{
			if(j == 0)			// first letter match
			{
				position = i;
			}
			j++; 
		}else
		{
			i -= j;				// reward to next;
			j = 0;
			position 	= -1;
		}
		i++;
	}
	if(needle[j] != '\0')		// needle has more letter
	{
		position = -1;
	}
	return position;
}


int main(int argc, char* argv[])
{
	int	ret;
	int val;
	int numsSize;
	int i;

	ret = strStr(argv[1],argv[2]);
	
	printf("%s \n", argv[1]);
	for(i = 0; i < ret; i++)
	{
		printf(" ");
	}
	printf("%s \n", argv[2]);
	printf("%d \n", ret);

}
