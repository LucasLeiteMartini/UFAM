import java.util.Scanner;

public class AreaVolume {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        int b = scan.nextInt();
        double r = (double) b;
        double pi = Math.PI;
        double a = pi * Math.pow(r,2);
        double v = (4.0/3.0) * (pi * Math.pow(r,3));

        System.out.printf("Um circulo com raio de %.2f centimetros tem uma area de %.2f centimetros quadrados.\n", r, a);
        System.out.printf("Uma esfera com raio de %.2f centimetros tem um volume de %.2f centimetros cubicos.\n", r, v);
    scan.close();
    }
}
