#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LEN	10000

char a[] = {'1','1','1','1','1','1','\0'};
char b[] = {'1','1','1','1','\0'};
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
char * addBinary(char * a, char * b){
	char *big, *small, *ret;
	int biglen, smalllen;
	int offset;
	int lenA, lenB;
	int bitA, bitB;
	int carry;
	int i;


	carry = 0;
	lenA = strlen(a);
	lenB = strlen(b);
	if(lenA > lenB)
	{
		big 		= a;
		small 		= b;
		biglen 		= lenA;
		smalllen	= lenB;
	}else
	{
		big 		= b;
		small 		= a;
		biglen 		= lenB;
		smalllen	= lenA;
	}
	offset = biglen - smalllen;

	printf("strlen(big) = %d, strlen(small) = %d \n", biglen, smalllen);
	printf("%s \n", big);
	for(i = 0; i < offset; i++)
	{
		printf(" ");
	}
	printf("%s \n", small);


	for (i = biglen-1; i >=0; i--)
	{
		bitA = big[i] - '0';

		if(i >= offset)
		{
			bitB = small[i-offset] - '0';
		}else
		{
			bitB = 0;
		}
		if(bitA > 1 && bitB > 1)
		{
			printf("wrong digit format at %d \n", i);
			return NULL;
		}

		printf("%d : %d + %d \n", i, bitA, bitB);
		if(carry)
		{
			if(bitA | bitB)
			{
				carry = 1;
			}else
			{
				carry = 0;
			}
			if(bitA & bitB)
			{
				big[i] = '1';
			}else
			{
				big[i] = '0';
			}
		}
		else
		{
			if(bitA & bitB)
			{
				big[i] = '0';
				carry = 1;
		
			}else
			{
				big[i] = (bitA | bitB) + '0';
				carry = 0;
			}
		}
	}

	ret = (char *)malloc(biglen+carry+1);

	if(carry)
	{
		ret[0] = '1';
	}
	for(i = 0; i < biglen; i++)
	{
		ret[i+carry] = big[i];
	} 
	ret[biglen+carry+1] = '\0';
	return ret;
}


int main(int argc, char* argv[])
{
	char	*ret;
	int 	retSize;
	int 	numsSize;
	int 	i;

	ret = addBinary(a, b);
	printf("%s \n", ret);

	if(ret != NULL)
	{
		free(ret);
	}
}
