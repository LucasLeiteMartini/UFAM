import java.util.Scanner;

public class AproximacaoPi {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        int a = scan.nextInt();
        double pi = 3.0;
        double count = 2.0;
        boolean flag = true;

        for(int i = 0; i < a; i++){
            System.out.printf("%f\n", pi);
            
            if(flag){
                pi += (4.0/(count * (count+1) * (count+2)));
            }else{
                pi -= (4.0/(count * (count+1) * (count+2)));
            }
        count += 2;
        flag = !flag;
        }
        
        scan.close();
    }
}
