#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int roman[] = {
	0,
 	0, 
 	100,	/*C*/
 	500,	/*D*/
 	0,
 	0,
 	0,
 	0,
 	1,		/*I*/
 	0,
 	0,
 	50, 	/*L*/
 	1000, 	/*M*/
 	0,		/*N*/
 	0,
 	0,
 	0,
 	0,
 	0,
 	0,
 	0,
 	5, 		/*V*/
 	0,
 	10,		/*X*/
 	0,
 	0
};

int romanToIntXX(char * s)
{
	int 	pending;
	int 	sum;
	int 	num;
	int 	i = strlen(s);

	sum = 0;
	num = 0;
	pending = 0;
	while(i--)
	{
		num = roman[*s - 'A'];

		printf("%c = %d \n", *s, num);
#if 1
		switch(num)
		{
			case 1:
				if(pending == 1)
				{
					num += pending;
					pending = 1;
				}else
				{
					pending = 1;
				}
				break;
			case 5:
				if(pending == 1)
				{
					num -= pending;
					pending = 0;
				}
				break;

			case 10:
				if(pending == 1)
				{
					num -= pending;
					pending = 0;
				}else
				{
					pending = 10;
				}
				break;
			case 50:
				if(pending == 10)
				{
					num -= pending;
					pending = 0;

				}else
				{
					num += pending;
				}
				break;
			case 100:
				if(pending == 10)
				{
					num -= pending;
					pending = 0;
				}else
				{
					pending = 100;
				}
				break;
			case 500:
				if(pending == 100)
				{
					num -= pending;
					pending = 0;
				}else
				{
					num += pending;
				}
				break;
			case 1000:
				if(pending == 100)
				{
					num -= pending;
					pending = 0;
				}else
				{
					num += pending;
				}
				break;
		}
#endif
		s++;
		if(pending == 0)
		{
			sum += num;
			printf("%d = %d \n", sum, num);
		}
	}
	sum += pending;
	return sum;
}
int roman_dict[26] = {0};

bool checkRoman(int a, int b)
{
	if(a >= b)
	{
		return true;
	}else
	{
		if(((a == 1) && (b == 5 || b == 10)) ||
		   ((a == 10) && (b == 50 || b == 100)) ||
		   ((a == 100) && (b == 500 || b == 1000)))
		{
			return true;
		}
	}
	return false;
}

int romanToInt(char* s) {
    int total = 0;
    int len = strlen(s);
    int i;
    roman_dict['I'-'A'] = 1;
    roman_dict['V'-'A'] = 5;
    roman_dict['X'-'A'] = 10;
    roman_dict['L'-'A'] = 50;
    roman_dict['C'-'A'] = 100;
    roman_dict['D'-'A'] = 500;
    roman_dict['M'-'A'] = 1000;

    for (i = 0; i < len; i++) {
    	if (checkRoman(roman_dict[s[i]-'A'] , roman_dict[s[i+1]-'A']) == false)
    	{
    		printf("%s is not the roman numeral \n", s);
    		return -1;
    	}
        if (i < len - 1 && roman_dict[s[i]-'A'] < roman_dict[s[i+1]-'A']) {
            total -= roman_dict[s[i]-'A'];
        } else {
            total += roman_dict[s[i]-'A'];
        }
    }
    return total;
}

int main(int argc, char* argv[])
{
	int ret;


	
	ret = romanToInt(argv[1]);
	printf("%s = %d \n", argv[1], ret);


}
