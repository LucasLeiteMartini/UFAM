import java.util.Scanner;

public class RaizDois {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        int n = scan.nextInt();

        double x = expansaoContinua(n);

        
        scan.close();
    }


    static double recursaoContinua(int n){
        if(n == 0){
            return (2.0 + (1.0/1.0));
        }
        double a = 2.0 + 1 / recursaoContinua(n-1);
        System.out.printf("%.14f\n", a-1);
        return a;
    }

    static double expansaoContinua(int n) {
        double a = 1.0+1.0/recursaoContinua(n-1);
        System.out.printf("%.14f\n", a);a
        return a;
    }
}
