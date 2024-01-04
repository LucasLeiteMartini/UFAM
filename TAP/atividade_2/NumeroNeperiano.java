import java.util.Scanner;

public class NumeroNeperiano {
    
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        
        int k = scan.nextInt();
        double sum = 0.0;
        for(int i = 0; i < k; i++){
            sum += 1.0/fatorial(i);
        }
        
        System.out.printf("%f\n", sum);

    scan.close();
    }
    
    
    
    
    public static long fatorial(int a){
        if(a == 0){
            return 1;
        }else{
            return a * fatorial(a-1);
        }
    }
}
