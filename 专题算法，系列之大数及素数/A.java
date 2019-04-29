import java.util.*;

import java.math.BigInteger;


public class A {
    public static void main(String[] args) {
        Scanner in = new Scanner (System.in);
        BigInteger a ,b;
        while (in.hasNext()) {
            a = in.nextBigInteger();
            b = in.nextBigInteger();
            System.out.println(a.mod(b));
        }
    }
}