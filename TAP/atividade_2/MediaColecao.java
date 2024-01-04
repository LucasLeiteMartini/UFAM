import java.util.Scanner;

public class MediaColecao {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        int cont = 0;
        int a = scan.nextInt();
        int soma = 0;
        while(a != -1){
            soma += a;
            a = scan.nextInt();
            cont++;
        }

        System.out.printf("%.2f\n", (double)soma/cont);

    scan.close();
    }
}
