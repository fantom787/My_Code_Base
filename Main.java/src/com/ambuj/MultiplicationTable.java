package com.ambuj;

import java.util.Scanner;

public class MultiplicationTable {
    public static void main(String[] args) {
        // your code goes here
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t-- > 0)
        {
            int n = sc.nextInt();
            int a[] = new int[n];
            int b = 0, c = 0, d = 0, e = 0;
            int f = 0;
            for (int i = 0; i < n; i++)
            {
                a[i] = sc.nextInt();
                if (a[i] == 1)
                {
                    d++;
                }
                else
                {
                    if (a[i] == 2)
                    {
                        c++;
                    }
                    e = e + a[i];
                    f++;
                    if (a[i] % 2 != 0)
                    {
                        b++;
                    }
                }
            }
            if (d == 1)
            {
                if (b % 2 == 0)
                {
                    System.out.println("chef");
                    continue;
                }
                if (c == 0)
                {

                    System.out.println("chefina");
                    continue;
                }
                e = e - 2;
                f--;
                if ((e - f) % 2 != 0)
                {

                    System.out.println("chefina");
                    continue;
                }
                else
                {

                    System.out.println("chef");
                    continue;
                }
            }
            else if (d > 1)
            {
                if ((e - f) % 2 != 0)
                {

                    System.out.println("chef");
                    continue;
                }
                else
                {

                    System.out.println("chefina");
                    continue;
                }
            }
            if (b % 2 != 0)
            {
                System.out.println("chef");
                continue;
            }
            else
            {
                System.out.println("chefina");
                continue;
            }
        }
    }


}
