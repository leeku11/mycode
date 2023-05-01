#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STRS_LEN	200
char 	comPrefix[MAX_STRS_LEN];

char * longestCommonPrefix(char ** strs, int strsSize)
{
	int 	i, j;
	char	a;
	bool	complete;


	for (i = 0; i < strsSize; i++)
	{
		printf("%d %s \n",i, strs[i]);
	}

	for (i = 0; i < MAX_STRS_LEN; i++)
	{
		a = strs[0][i];
		for (j = 1; j < strsSize; j++)
		{
			printf("strs[%d][%d] - %c\n", j, i, strs[j][i]);
			if(strs[j][i] != a)
			{
				break;
			}
		}
		if(j == strsSize)		// all character is idential
		{
			comPrefix[i] = a;
		}
		else
		{
			comPrefix[i] = '\0';
			break;
		}
	}
	return comPrefix;
}


int main(int argc, char* argv[])
{
	char *s;
	int i;

	s = longestCommonPrefix(&argv[1], argc-1);

	printf("longest common prefix is %s \n", s);
}
