package com.ambuj;

import java.util.Scanner;

public class MultiplicationTable {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.println("Enter A desired Number");
        int num = in.nextInt();
        String ans = table(num);
        System.out.println(ans);
    }

    static String table(int num) {
        String s = new String();
        for (int i = 1; i < 11; i++) {
            s += num + " * " + i + " = " + num * i + "\n";
        }
        return s;
    }
}
