import java.util.Scanner;
import java.math.BigInteger;

public class J {
    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        BigInteger a;
        int  b;
        while (cin.hasNext()) {
            a = cin.nextBigInteger();
            b = cin.nextInt();
            
            System.out.println(a.pow(b));
        }
        cin.close();
    }
}

/*

很开心能够这样写完这样一个java的程序，但是很不幸的是 由于前面有一些题目 可以直接使用java的 modpow 直接写完，其实内部是直接封装了一个
*/