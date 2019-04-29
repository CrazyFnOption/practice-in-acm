import java.util.Scanner;
import java.math.BigInteger;


public class I {
    public static void main(String[] args) {
        Scanner cin = new Scanner (System.in);
        BigInteger a,b,c;
        while (cin.hasNext()) {
            a = cin.nextBigInteger();
            b = cin.nextBigInteger();
            c = cin.nextBigInteger();
            System.out.println(a.modPow(b, c));
        }
        cin.close();
    }
}

/*
    有时间考虑一下这道题的快速幂类型的求法。
*/ 