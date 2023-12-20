import java.util.Locale;
import java.util.Scanner;

public class PinturaMuro {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in).useLocale(Locale.US);

        float preco = scan.nextFloat();

        System.out.printf(Locale.US,"%.1f", (preco * 36)+100);

        scan.close();
    }
}
