package com.ambuj;

public class Main {
    public static void main(String[] args) {
        int a = 5;
        int b = 5;
//        char c = '+';
//        System.out.println("Ambuj" + a + b);
//        System.out.println("ambuj is %d");
        int sum = sum2(a, b);
        System.out.println(sum);
    }

     static int sum2(int a, int b) {
        int sum = a + b;
        return sum;
    }
}
