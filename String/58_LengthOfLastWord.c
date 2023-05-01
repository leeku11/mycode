#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LEN	10000

char *str = "luffy is still joyboya  ";

int printArray(int *num, int length)
{
	int i;
	for(i = 0; i < length; i++)
	{
		printf("%d ", num[i]);
	}
	printf("	: %d\n", length);
}


int lengthOfLastWord(char * s){
	int i;
	int lenLast;

	i 		= 0;
	lenLast = 0;
	while(*s != '\0')
	{
		if(*s == ' ' || *s == '\t')
		{
			if(i != 0)
			{
				lenLast = i;
			}
			i 		= 0;
		}else
		{
			i++;
		}
		s++;
	}
	if(i != 0)
	{
		lenLast = i;
	}
	return lenLast;
}

int main(int argc, char* argv[])
{
	int	ret;
	int val;
	int numsSize;
	int i;
	int target;

	ret = lengthOfLastWord(str);
	
	printf("------ %d \n", ret);
}
