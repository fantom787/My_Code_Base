

import java.util.Scanner;

public class Calculator {
    public static void main(String[] args) {
        int ans = 0, num1, num2;
        char op;
//        to take input
        Scanner input = new Scanner(System.in);
        System.out.println("Calculator Program !!");
        while (true) {
//            take the operator as input
            System.out.println("Enter Operator :");
            op = input.nextLine().trim().charAt(0);
            if (op == '+' || op == '-' || op == '*' || op == '/' || op == '%') {
//            take num1 as input
                System.out.println("Enter Num1 :");
                num1 = input.nextInt();
//            take num2 as input
                System.out.println("Enter Num2 :");
                num2 = input.nextInt();
                if (op == '+') {
                    ans = num1 + num2;
                    System.out.println(ans);
                    continue;
                } else if (op == '-') {
                    ans = num1 - num2;
                    System.out.println(ans);
                    continue;
                } else if (op == '*') {
                    ans = num1 * num2;
                    System.out.println(ans);
                    continue;
                } else if (op == '/') {
                    if (num2 != 0) {
                        ans = num1 + num2;
                        System.out.println(ans);
                        continue;
                    }
                } else if (op == '%') {
                    ans = num1 % num2;
                    System.out.println(ans);
                    continue;
                }
            } else if (op == 'x' || op == 'X') {
                break;
            } else {
                System.out.println("Invalid Operator!!");
                continue;
            }
            break;
        }
    }
}
