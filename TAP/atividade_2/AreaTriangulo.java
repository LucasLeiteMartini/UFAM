import java.util.Locale;
import java.util.Scanner;

public class AreaTriangulo {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        double a = scan.nextDouble();
        double b = scan.nextDouble();
        double c = scan.nextDouble();

        if((a+b) <= c || (a+c) <= b || (b+c) <= a ){
            System.out.println("Triangulo Invalido");
        }else{

        double s = (a+b+c)/2;

        double sqrt = Math.sqrt((s * (((s-a) * (s-b)) * (s-c))));

        System.out.printf(Locale.US,"%.2f", sqrt);
        }
        scan.close();
    }
}