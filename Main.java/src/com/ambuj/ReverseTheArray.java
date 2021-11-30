package com.ambuj;

import java.util.ArrayList;
import java.util.Arrays;

public class ReverseTheArray {
    public static void main(String[] args) {

        int[] arr = {1, 2, 3, 4, 5, 6, 7, 8, 9,10};
        System.out.println(Arrays.toString(arr));
        reverse(arr);
        System.out.println(Arrays.toString(arr));

    }

    private static void reverse(int[] arr) {
        for (int i = 0; i < arr.length / 2; i++) {
            swap(arr, i, arr.length - 1 - i);
        }
    }

    static void swap(int[] arr, int min, int max) {
        int temp = arr[min];
        arr[min] = arr[max];
        arr[max] = temp;
    }
}
