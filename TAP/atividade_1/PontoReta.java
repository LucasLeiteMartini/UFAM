import java.util.Locale;
import java.util.Scanner;

class PontoReta{
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in).useLocale(Locale.US);

        double x = scan.nextDouble();
        double y = scan.nextDouble();

        if(((2*x) + y) == 3){
            System.out.printf("Ponto (%.1f, %.1f) pertence a reta 2x + y = 3.", x, y);
        }else{
            System.out.printf("Ponto (%.1f, %.1f) nao pertence a reta 2x + y = 3.", x, y);
        }


    scan.close();
    }
}