#include <stdio.h>
#include <math.h>

int main()
{
     int p = 50000, r= 5,  t= 5;
     int ci = p*(pow((1+r/100),t));

     printf("the simple inrest of \npriciple %d \nrate %d \n for time pd %d \nis : %d",p,r,t,ci);
      
     return 0;
}