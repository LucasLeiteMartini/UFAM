import java.util.Scanner;

public class AproximacaoSeno {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        int grau = scan.nextInt();
        int k = scan.nextInt();
        int exp = 3;
        
        boolean flag = true;

        double ang = Math.toRadians(grau);
        double x = ang;

        for(int i = 0; i < k; i++){
            System.out.printf("%.10f\n", x);
            double pot = Math.pow(ang, exp);
            long fat = fatorial(exp);
            if(flag){
                x -= pot/fat;
            }else{
                x += pot/fat;
            }
            exp += 2;
            flag = !flag;
        }
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
