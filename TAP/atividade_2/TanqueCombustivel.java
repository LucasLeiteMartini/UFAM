import java.util.Scanner;

public class TanqueCombustivel {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        int a = scan.nextInt();
        int b = scan.nextInt();
        int op = scan.nextInt();

        double pi = Math.PI;
        double r = (double) a;
        double x = (double) b;
        double v = (4.0/3.0) * (pi * Math.pow(r,3));
        double calota = ((pi/3) * Math.pow(x,2)) * ((3*r) - x);

        switch (op) {
            case 1:
                System.out.printf("%.4f\n", calota);
                break;
            case 2:
                System.out.printf("%.4f\n", (v-calota));
                break;
            default:
                break;
        }
    scan.close();
    }
}
