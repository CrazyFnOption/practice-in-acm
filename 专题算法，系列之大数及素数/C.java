import java.util.*;
import java.math.BigInteger;

public class C {
    public static void main(String[] args) {
        
        
        Scanner in = new Scanner(System.in);
        
        while (in.hasNext()) {
            int n = in.nextInt();
            BigInteger b = new BigInteger("1");
            BigInteger c = new BigInteger("1");
            for (int i = 0; i < n; i++) {
                b = b.multiply(c);
                c = c.add(new BigInteger("1"));
            }
            System.out.println(b);       
        }
    }
}