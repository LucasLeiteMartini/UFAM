import java.util.Scanner;

public class SomaColecao {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        int a = scan.nextInt();
        int soma = 0;
        while(a != -1){
            soma += a;
            a = scan.nextInt();
        }

        System.out.printf("%d\n", soma);


    scan.close();
    }    
}
