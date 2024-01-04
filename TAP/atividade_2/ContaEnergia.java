import java.util.Scanner;

public class ContaEnergia {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        int a = scan.nextInt();
        char tipo = scan.next().charAt(0);
        double valor = (double) a;
        if(valor > 0){
            switch (tipo) {
                case 'R':
                    if(valor <= 500 && valor > 0){
                        System.out.printf("%.2f", (valor*0.4));
                    }else{
                        System.out.printf("%.2f", (valor*0.65));
                    }
                    break;
                case 'C':
                    if(valor <= 1000 && valor > 0){
                        System.out.printf("%.2f", (valor*0.55));
                    }else{
                        System.out.printf("%.2f", (valor*0.60));
                    }
                    break;
                case 'I':
                    if(valor <= 5000 && valor > 0){
                        System.out.printf("%.2f", (valor*0.55));
                    }else{
                        System.out.printf("%.2f", (valor*0.60));
                    }
                    break;
                default:
                    System.out.println("-1.00");
                    break;
            }
        }else{
            System.out.println("-1.00");
        }
    scan.close();
    }
}
