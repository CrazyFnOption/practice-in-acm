import java.util.Scanner;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.math.BigDecimal;

public class G {

    public static void main(String[] args) {

        Scanner cin = new Scanner(System.in);
        BigDecimal a,b,res;
        while (cin.hasNext()) {
            a = cin.nextBigDecimal();
            b = cin.nextBigDecimal();
            res = a.add(b);
            res = res.stripTrailingZeros();
            String s = res.toPlainString();

            System.out.println(s);
        }

        
    }
}