#include <stdio.h>

int main()
{
    int n = 10, m = 10;
    int arr[n][m];
    /*  sr----> starting row
    er----> ending row
    sc---->starting coloumnn
    ec----> ending coloumn
    */
    int sr = 0, er = m, sc = 0, ec = n, num = 1;

    while (sr < er && sc < ec)
    {
        // for 1st row
        for (int i = sc; i < ec; i++)
        {
            arr[sr][i] = num++;
        }
        sr++;

        // for last coloumn
        for (int i = sr; i < er; i++)
        {
            arr[i][ec-1] = num++;
        }
        ec--;

        // for last row
        for (int i = ec-1; i >=sc; i--)
        {
            arr[er-1][i] = num++;
        }
        er--;

        // for 1st coloumn
        for (int i = er-1; i >= sr; i--)
        {
            arr[i][sc] = num++;
        }
        sc++;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%3d ",arr[i][j]);
        }
        printf("\n");
    }
    

    return 0;
}