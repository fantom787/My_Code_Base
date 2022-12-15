import java.io.*;
import java.util.*;

public class Main {

  static Main2 admin = new Main2();

  public static void main(String[] args) {
    admin.start();
  }
}

class Main2 {

  //---------------------------------INPUT READER-----------------------------------------//
  public BufferedReader br;
  StringTokenizer st = new StringTokenizer("");

  String next() {
    while (!st.hasMoreTokens()) {
      try {
        st = new StringTokenizer(br.readLine());
      } catch (IOException e) {
        e.printStackTrace();
      }
    }
    return st.nextToken();
  }

  int ni() {
    return Integer.parseInt(next());
  }

  long nl() {
    return Long.parseLong(next());
  }

  double nd() {
    return Double.parseDouble(next());
  }

  String ns() {
    return next();
  }

  int[] na(long n) {
    int[] ret = new int[(int) n];
    for (int i = 0; i < n; i++) ret[i] = ni();
    return ret;
  }

  long[] nal(long n) {
    long[] ret = new long[(int) n];
    for (int i = 0; i < n; i++) ret[i] = nl();
    return ret;
  }

  Integer[] nA(long n) {
    Integer[] ret = new Integer[(int) n];
    for (int i = 0; i < n; i++) ret[i] = ni();
    return ret;
  }

  Long[] nAl(long n) {
    Long[] ret = new Long[(int) n];
    for (int i = 0; i < n; i++) ret[i] = nl();
    return ret;
  }

  //--------------------------------------PRINTER------------------------------------------//
  PrintWriter w;

  void p(int i) {
    w.println(i);
  }

  void p(long l) {
    w.println(l);
  }

  void p(double d) {
    w.println(d);
  }

  void p(String s) {
    w.println(s);
  }

  void pr(int i) {
    w.print(i);
  }

  void pr(long l) {
    w.print(l);
  }

  void pr(double d) {
    w.print(d);
  }

  void pr(String s) {
    w.print(s);
  }

  void pl() {
    w.println();
  }

  //--------------------------------------VARIABLES-----------------------------------------//
  long lma = Long.MAX_VALUE, lmi = Long.MIN_VALUE;
  int ima = Integer.MAX_VALUE, imi = Integer.MIN_VALUE;
  long mod = 1000000007;

  {
    w = new PrintWriter(System.out);
    br = new BufferedReader(new InputStreamReader(System.in));
    try {
      if (
        new File(System.getProperty("user.dir")).getName().equals("Main_CP")
      ) {
        w =
          new PrintWriter(
            new OutputStreamWriter(new FileOutputStream("output.txt"))
          );
        br =
          new BufferedReader(
            new InputStreamReader(new FileInputStream("input.txt"))
          );
      }
    } catch (Exception ignore) {}
  }

  //----------------------START---------------------//
  void start() {
    int t = ni();
    while (t-- > 0) solve();

    w.close();
  }

  void solve() {
    String str = ns();
    char[] strr = str.toCharArray();
    int n = strr.length;

    int cost = Math.abs(strr[0] - strr[n - 1]);
    int min = Math.min(strr[0], strr[n - 1]);
    int max = Math.max(strr[0], strr[n - 1]);

    List<Integer> li = new ArrayList<>();

    for (int i = 0; i < n; i++) {
      if (strr[i] >= min && strr[i] <= max) li.add(i);
    }

    boolean mintomax = (min == strr[0]);

    li.sort(
      (a, b) -> {
        if (strr[a] == strr[b]) return Integer.compare(a, b); else return (
          ((mintomax) ? 1 : -1) * Integer.compare(strr[a], strr[b])
        );
      }
    );

    p(cost + " " + li.size());
    for (int i : li) {
      pr((i + 1) + " ");
    }
    pl();
  }
}
