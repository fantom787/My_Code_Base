package com.ambuj;

import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class Solution {
    static int answer(String s, String f) {
        if (f.length() == 1) {
            int comp = f.charAt(0);
            int sum = 0;
            int n = s.length();
            for (int i = 0; i < n; i++) {
                int temp = s.charAt(i);
                int dif = Math.abs(temp - comp);
                if (dif > 13) {
                    dif = 26 - dif;
                }
                sum += dif;
            }
            return sum;
        } else {

            Set<Character> F = new HashSet<>();
            for (int i = 0; i < f.length(); i++) {
                F.add(f.charAt(i));
            }
            int n = s.length(), sum = 0;
            for (int i = 0; i < n; i++) {
                char c = s.charAt(i);
                if (!F.contains(c)) {
                    int min = Integer.MAX_VALUE;
                    for (char S : F) {
                        int temp = Math.abs(c - S);
                        if (temp > 13) {
                            temp = 26 - temp;
                        }
                        if (temp < min) {
                            min = temp;
                        }
                    }
                    sum += min;

                }
            }
            return sum;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        for (int i = 0; i < t; i++) {
            String S = sc.next();
            String F = sc.next();
            System.out.println("Case #"+(i+1)+": "+answer(S,F));
        }
    }
}
