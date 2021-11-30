package com.ambuj;

public class ArmstrongNumber {
    public static void main(String[] args) {
        int n = 13;
        System.out.println(isArmstrong(n));
    }

    static boolean isArmstrong(int n) {
        int original = n;
        int sum = 0;
        while (n > 0) {
            int rem = n % 10;
            n /= 10;
            sum += Math.pow(rem, 3);
        }
        if (sum == original) {
            return true;
        }
        return false;
    }
}
