import java.util.Scanner;
import java.util.ArrayList;
import java.util.Locale;


public class AreaPoligono {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in).useLocale(Locale.US);
        
        ArrayList<Double> xArrayList = new ArrayList<>();
        ArrayList<Double> yArrayList = new ArrayList<>();
        
        double x = scan.nextDouble();
        while(x != -1){
            xArrayList.add(x);
            x = scan.nextDouble();
        }

        double y = scan.nextDouble();
        while(y != -1){
            yArrayList.add(y);
            y = scan.nextDouble();
        }

        double soma = 0.0;

        for(int i = 0; i < xArrayList.size() - 2; i++){
            int nextIndex = (i + 1) % xArrayList.size();
            soma += (xArrayList.get(nextIndex) + xArrayList.get(i)) * (yArrayList.get(nextIndex) - yArrayList.get(i));
        }

        soma = Math.abs(soma);

        System.out.printf(Locale.US,"%.4f\n", (soma/2));

    scan.close();
    }
}
