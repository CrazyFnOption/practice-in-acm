import java.math.BigDecimal;
import java.util.Scanner;
import java.io.BufferedInputStream;
public class E {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        while (in.hasNext()) {
            BigDecimal r;
            int n;
            r = in.nextBigDecimal();
            n = in.nextInt();
            BigDecimal ans;
            ans = r.pow(n);
            ans = ans.stripTrailingZeros();
            String res = ans.toPlainString();

            while (res.startsWith("0")) {res =res.substring(1);}
            System.out.println(res);
            
            
        }
        in.close();
    }
}