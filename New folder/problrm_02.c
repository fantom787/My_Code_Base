// finding mode 2nd way

#include <stdio.h>

int mode(int a[], int n)
{
    int maxValue = 0, maxCount = 0, i, j;

    for (i = 0; i < n; i++)
    {
        int count = 0;

        for (j = 0; j < n; j++)
        {
            if (a[j] == a[i])
            {
                count++;
            }
        }

        if (count > maxCount)
        {
            maxCount = count;
            maxValue = a[i];
        }
    }

    return maxValue;
}

int main()
{
    int n = 5;
    int a[] = {0, 6, 6, 7, 7};

    printf("Mode = %d ", mode(a, n));

    return 0;
}