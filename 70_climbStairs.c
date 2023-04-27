#include <stdio.h>
#include <stdlib.h>

// Sqrt(999999999) = 31622

int climbStairs(int n){
   int i;
   int numsOfPossibleTwoSteps;
   int ways;

   numsOfPossibleTwoSteps = n / 2;
   ways = 0;
   for (i = 0; i < numsOfPossibleTwoSteps; i++)
   {
      ways += (n - i);
   }
   return ways;

}

int climbStairsAI(int n) {
    int n2 = 0, n1 = 1;
    int n0 = 0;
    for (int i = 0; i < n; i++) {
        printf("N-2 %d, N-1 %d \n", n2, n1);

        n0 = n1 + n2;    // the way of N is, (way(N-2)+2step) + (way(N-1)+1step)
        n2 = n1;
        n1 = n0;
    }
    return n0;
}

int main(int argc, char *argv[])
{
   int ret;
   int a;

   a = atoi(argv[1]);
   ret = climbStairsAI(a);

   printf("%d of Stairs can be climbed in %d ways of (1 step or 2)\n", a, ret);

   return 0;
}