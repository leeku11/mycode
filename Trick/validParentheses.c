#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STRS_LEN	10000
char 	stack[MAX_STRS_LEN];
int		idx;

int cPush(char c)
{
	stack[idx] = c;
	idx++;
}
char cPop(void)
{
	idx--;
	return stack[idx];
}

bool checkParentheses(char c, char d)
{
	printf("%c - %c\n", c, d);

	if(c == '(')
	{
		return (d == ')');
	}
	else if(c == '{')
	{
		return (d == '}');
	}
	else if(c == '[')
	{
		return (d == ']');
	}
	return false;
}

bool isValid(char * s)
{
	int 	i;
	char 	last;
	bool	ret;

	ret = true;
	for(i = 0; i < strlen(s); i++)
	{
		last = s[i];
		if(last == '(' || last == '{' || last == '[')			// open
		{
			printf("push : stack[%d] %c \n", idx, last);
			cPush(last);
		}else													// close
		{
			printf("pop : stack[%d] %c \n", idx, stack[idx]);
			ret = checkParentheses(cPop(), last);
			if(ret == false)
			{
				break;
			}
		}
	}
	return ret;
}


int main(int argc, char* argv[])
{
	bool	ret;

	ret = isValid(argv[1]);

	printf("%s is ", argv[1]);
	if(ret == false)
	{
		printf("not ");
	}
	printf("valid \n");
}
