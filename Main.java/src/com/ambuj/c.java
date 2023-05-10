import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
public class c {
    static int solve(int n,int arr[])
    {
        int dp[]=new int[n+1];
        dp[1]=1;
        for(int i=1;i<=n;i++)
        {
            dp[i]=1;
        }
        for(int i=2;i<=n;i++)
        {
            for(int j=1;j*j<=i;j++)
            {
                if(i%j==0)
                {
                    int val1=j;
                    int val2=i/j;
                    if(arr[i-1]>arr[val1-1])
                        dp[i]=Math.max(dp[i],dp[val1]+1);

                    if(val1!=val2)
                    {
                        if(arr[i-1]>arr[val2-1])
                            dp[i]=Math.max(dp[i],dp[val2]+1);
                    }
                }
            }
        }
        int max=0;
        for(int j=1;j<=n;j++)
            max=Math.max(max,dp[j]);
        return max;
    }
    public static void main(String[] args) throws java.lang.Exception {

        BufferedReader buf = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb=new StringBuilder();

        int t=Integer.parseInt(buf.readLine());

        for(int i=0;i<t;i++) {
            int n=Integer.parseInt(buf.readLine());
            String st2[]=(buf.readLine()).split(" ");
            int arr[]=new int[n];
            for(int j=0;j<n;j++)
                arr[j]=Integer.parseInt(st2[j]);
            sb.append(solve(n,arr)+"\n");
        }
        System.out.println(sb);

    }
}