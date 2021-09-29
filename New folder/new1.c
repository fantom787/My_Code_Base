#include <stdio.h>
#include <math.h>

int main()
{
    int p = 50000, r = 5, t = 5;
    int si = (p * r * t) / 100;
    int ci = p * (pow((1 + r / 100), t));
    printf("the simple intrest of priciple %d ,rate %d , for time pd %d is : %d", p, r, t, si);
    printf("the compound intrest of \npriciple %d \nrate %d \n for time pd %d \nis : %d", p, r, t, ci);

    return 0;
}