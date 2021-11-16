package com.ambuj;

public class Switch {
    public static void main(String[] args) {
        int a  = 1;
        switch (a)
        {
            case 1:
                System.out.println("ambuj");
                break;
            case 2:
                System.out.println("kumar");
                break;
            case 3:
                System.out.println("dubey");
                break;
        }
//        enhanced way to write switch statement
//        switch (a) {
//            case 1 -> System.out.println("ambuj");
//            case 2 -> System.out.println("kumar");
//            case 3 -> System.out.println("dubey");
//        }
    }
}
