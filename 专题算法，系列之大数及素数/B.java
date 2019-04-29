import java.util.*;
import java.math.BigInteger;

public class B {
    public static void main(String[] args) {
        int T,Case = 0;
        BigInteger a,b;
        Scanner in = new Scanner(System.in);
        T = in.nextInt();
        while (T != 0) {
            T--;
            if (Case > 0) System.out.println();
            a = in.nextBigInteger();
            b = in.nextBigInteger();
            System.out.printf("Case %d:",++Case);
            System.out.println();
            System.out.print(a);
            System.out.print(" + ");
            System.out.print(b);
            System.out.print(" = ");
            System.out.println(a.add(b));            
        }
    }
}