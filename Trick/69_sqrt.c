#include <stdio.h>
#include <stdlib.h>

// Sqrt(999999999) = 31622

int mySqrt(int x){
   long long low, mid, high;
   long long mul, mulround;
   int i;
   i = 0;
   low = 0;
   high = x;
   while(low <= high)
   {
      mid = low + (high-low)/2;

      mul = mid * mid;
      mulround = (mid+1) * (mid+1);
      printf("-->%lld : %lld : %lld \n", low, mid, high);
      printf("%d : %lld x %lld = %lld \n", i++, mid, mid, mul);
      

      if((mul <= x) && (x < mulround))
      {
         break;
      }else if(mul > x)
      {
         high = mid - 1;
      }else if(mulround <= x)
      {
         low = mid + 1;
      }
      printf("<--%lld : %lld : %lld \n", low, mid, high);
   }
   return mid;
}

int main(int argc, char *argv[])
{
   int ret;
   int a;

   a = atoi(argv[1]);
   ret = mySqrt(a);

   printf("Sqrt(%d) = %d \n", a, ret);

   return 0;
}