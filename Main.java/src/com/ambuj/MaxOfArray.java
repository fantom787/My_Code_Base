package com.ambuj;

public class MaxOfArray {
    public static void main(String[] args) {
        int[] arr = {4, 8, 3, 2, 9, 2, 9, 24, 6, 8};
        System.out.println(max(arr));

    }

    private static int max(int[] arr) {
        int max = Integer.MIN_VALUE;
        for (int i : arr) {
            max = Math.max(i, max);
        }
        return max;
    }
}
