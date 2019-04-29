import java.util.*;
import java.math.BigDecimal;
import java.math.BigInteger;

public class F {

    public static String[] dp;

    public static String fun(int x) 
    {
        if (dp[x] != null) return dp[x];
        BigInteger a = new BigInteger(fun(x - 1));
        BigInteger b = new BigInteger(fun (x - 2));
        return dp[x] = a.add(b).toString();
        
    }
    public static void main(String[] args) {
        
        Scanner in = new Scanner(System.in);
        int T,x;
        dp = new String [1005];
        T = in.nextInt();
        dp[1] = "1";
        dp[2] = "1"; 
        while (T != 0) {
            T--;
            x = in.nextInt();
            System.out.println(fun(x));
            
        }
    }
}