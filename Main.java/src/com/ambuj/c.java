import java.util.Scanner;
import java.util.ArrayList;

public
class c {
    public
    static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int t = scanner.nextInt();

        while (t-- > 0) {
            int n = scanner.nextInt();
            int m = scanner.nextInt();
            int d = scanner.nextInt();

            ArrayList<Integer> arr = new ArrayList<>();
            for (int i = 0; i < m; ++i) {
                arr.add(scanner.nextInt());
            }

            int start = 0;
            if (arr.get(0) != 1) {
                start = 1;
                arr.add(0, 1);
            }
            arr.add(n + 1);
            n = arr.size();
            int ans = 0;
            for (int i = 1; i < n; ++i) {
                ans += f(arr.get(i - 1), arr.get(i), d);
            }
            int a2 = ans;
            int newans = ans;
            for (int i = 1; i < n - 1; ++i) {
                int cur = f(arr.get(i - 1), arr.get(i + 1), d) - f(arr.get(i - 1), arr.get(i), d) - f(arr.get(i), arr.get(i + 1), d);
                newans = a2 + cur;
                ans = Math.min(ans, newans);
            }
            int cnt = 0;
            for (int i = 1; i < n - 1; ++i) {
                int cur = f(arr.get(i - 1), arr.get(i + 1), d) - f(arr.get(i - 1), arr.get(i), d) - f(arr.get(i), arr.get(i + 1), d);
                newans = a2 + cur;
                if (newans == ans)
                    cnt += 1;
            }
            if (ans == a2 && start == 0) {
                cnt += 1;
            }
            System.out.println(ans + " " + cnt);
        }
    }

    public
    static int f(int x, int y, int d) {
        boolean e = ((y - x) % d) == 0;
        return (y - x) / d + 1 - (e ? 1 : 0);
    }
}