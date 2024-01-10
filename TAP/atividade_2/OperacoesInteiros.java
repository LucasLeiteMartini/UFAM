import java.util.Scanner;
import java.util.ArrayList;

public class OperacoesInteiros {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        while(true){
            ArrayList<Double> doublesArrayList = new ArrayList<>();
            
            double elem;
            int countPair = 0;
            int countOdd = 0;
            double soma = 0;
            double min = Double.POSITIVE_INFINITY, max = Double.NEGATIVE_INFINITY;
            
            
            while ((elem = scan.nextDouble()) != -1) {
                doublesArrayList.add(elem);
                countPair += (elem % 2  == 0) ? 1 : 0;
                countOdd += (elem % 2  != 0) ? 1 : 0;
                soma += elem;
                min = Math.min(min, elem);
                max = Math.max(max, elem);
            }
            
            if(doublesArrayList.isEmpty()){
                break;
            }

            double tamanho = doublesArrayList.size();
            double media  = soma / tamanho;

            System.out.printf("%.0f\n", tamanho);
            System.out.printf("%d\n", countPair);
            System.out.printf("%d\n", countOdd);
            System.out.printf("%.0f\n", soma);
            System.out.printf("%.2f\n", media);
            System.out.printf("%.0f\n", max);
            System.out.printf("%.0f\n", min);
            

        }
    
    scan.close();
    }
}