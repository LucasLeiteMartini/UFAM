import java.util.ArrayList;
import java.util.Locale;
import java.util.Scanner;

public class Mediana {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        ArrayList<Double> doublesArrayList = new ArrayList<>();
        
        double a;
    
        while((a = scan.nextDouble()) != -1){
            doublesArrayList.add(a);
        }
        
        if(doublesArrayList.size() % 2 == 0){
            int index = doublesArrayList.size() / 2;
            double mediana = (doublesArrayList.get(index) + doublesArrayList.get(index-1))/2;
            System.out.printf(Locale.US,"%.1f\n", mediana);
        }else{
            int index = doublesArrayList.size()/2;
            double mediana = doublesArrayList.get(index);
            System.out.printf(Locale.US,"%.1f", mediana);
        }
        
        
        
        
        
        
        scan.close();
    }

    

}
