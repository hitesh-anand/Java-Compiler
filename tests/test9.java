
//import statement and basic loops
import java.util.*;

public class test9 {
    public int gcdExtended(int a, int b, int x, int y) {
        if (a == 0) {
            x = 0;
            y = 1;
            return b;
        }

        int x1 = 1, y1 = 1;
        int gcd = gcdExtended(b % a, a, x1, y1);
        x = y1 - (b / a) * x1;
        y = x1;
        return gcd;
    }

    public int gcdloop(int a, int b) {
        int gcd = 1;

        for (int i = 1; i <= a && i <= b; ++i) {
            if (a % i == 0 && b % i == 0)
                gcd = i;
        }
        return gcd;
    }

    public void main(String[] args) {
        int x = 1, y = 1;
        int a = 35, b = 15;
        int g = gcdExtended(a, b, x, y);
        System.out.println("gcd=" + g);
    }
}
