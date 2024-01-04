import java.util.Locale;
import java.util.Scanner;

public class Desconto {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in).useLocale(Locale.US);

        double preco = scan.nextDouble();

        if(preco > 200.0){
            double desconto = preco - (preco * 0.05);
            
            System.out.printf("%.2f\n", desconto);

        }else{
            System.out.printf("%.2f", preco);
        }


    scan.close();
    }
}
