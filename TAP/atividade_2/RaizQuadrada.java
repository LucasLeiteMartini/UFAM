import java.util.Scanner;

public class RaizQuadrada {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        double a = scan.nextDouble();

        a = Math.sqrt(a);

        System.out.printf("%.3f", a);

    scan.close();

    }
}
