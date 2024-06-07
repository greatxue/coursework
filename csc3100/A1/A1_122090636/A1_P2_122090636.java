package A1_122090636;
import java.util.Scanner;

public class A1_P2_122090636 {
    private static final long MOD = 998244353; // standard way to clarify a Java constant

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        long n = scanner.nextLong();
        long m = scanner.nextLong();
        long p = scanner.nextLong();

        long total = 0;
        for (long i = 0; i < p; i++) {
            long x = scanner.nextLong();
            long y = scanner.nextLong();
            long k = scanner.nextLong(); 
            
            // Refer to the report for detailed explanation.
            long rectangles = (x * y * (n - x + 1) * (m - y + 1)) % MOD;
            total = (total + (rectangles * k) % MOD) % MOD;
        }

        System.out.println(total);
        scanner.close();
    }
}
