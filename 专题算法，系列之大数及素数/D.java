import java.util.*;
import java.math.BigInteger;
import java.math.BigDecimal;
public class D{
    public static void main(String[] args) {

        Scanner in = new Scanner(System.in);
        BigDecimal b ;
        BigDecimal c ;
        while (in.hasNext()) {
            b = in.nextBigDecimal();
            c = in.nextBigDecimal();
            b = b.stripTrailingZeros();
            c = c.stripTrailingZeros();

            if (b.equals(c))
                System.out.println("YES");
            else System.out.println("NO");
        }
    }
}