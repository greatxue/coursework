import java.util.Scanner;

public class GridSum {
    private static final long MOD = 998244353;

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
            
            long left_up = x * y
            long right_down = (n - x + 1) * (m - y + 1)
            long rectangles = (left_up * right_down) % MOD;
            total = (total + (rectangles * k) % MOD) % MOD;
        }

        System.out.println(total);
        scanner.close();
    }
}
