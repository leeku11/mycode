#include <stdio.h>
#include <stdbool.h>

int powerOfTen(int a)
{
	int i;
	int pow;

	pow = 1;
	for(i = 0; i < a; i++)
	{
		pow = pow * 10;
	}
	printf("%d pow of 10 is %d \n",a, pow);

	return pow;
}
bool isPalindrome(int x)
{
	int i = 0;
	int a = x;
	int ms, ls;
	bool ret;

	ret = true;
	// how many digit
	while(a > 0)
	{
		a = a / 10;
		i++;
	}
	printf("%d \n ", i);

	// most left digit
	ms = powerOfTen(i-1);
	// most right digit
	ls = 1;


	while (ms >= ls)
	{
		if(((x / ms) % 10) != ((x / ls) % 10))
		{
			ret = false;
			printf("%d %d vs %d \n",x, ((x / ms) % 10), ((x / ls) % 10));
			break;
		}
		ms /= 10;
		ls *= 10;
	}

	return ret;
}

int main(int argc, char* argv[])
{
	int	number;
	bool ret;
	number = atoi(argv[1]);
	
	ret = isPalindrome(number);

	printf("%d is ", number); 
	if (ret == false)
	{
		printf("not "); 
	}
	printf("palindrom \n");
}
