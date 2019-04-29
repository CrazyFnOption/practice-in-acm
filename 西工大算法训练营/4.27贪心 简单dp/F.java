import java.util.Scanner;
import java.math.BigInteger;
public class Main {
    
    public static void main(String[] args) {
        
        int n,k;
        Scanner in = new Scanner(System.in);
        while (in.hasNext()) {
            BigInteger[] dp = new BigInteger[1005];
            n = in.nextInt();
            k = in.nextInt();
            dp[0] = new BigInteger("1");
            for (int i = 1; i <= n; i++) {
                dp[i] = new BigInteger("0");
            }
            for (int i = 1; i <= k; i++) {
                for (int j = i; j <= n; j++) {
                    dp[j] = dp[j].add(dp[j - i]);
                }
            }
           System.out.println(dp[n]); 
        }
    }
}