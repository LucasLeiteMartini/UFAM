import java.util.Scanner;

public class CaixaEletronico {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        int valor = scan.nextInt();
        int v50, v10, v2;

        if(valor < 0 || valor % 2 != 0){
            System.out.println("Valor Invalido");
        }else{

        v50 = valor / 50;
        valor = valor % 50;
        v10 = valor / 10;
        valor = valor % 10;
        v2 = valor / 2;
        valor = valor % 2;

        System.out.printf("%d notas de R$50, %d notas de R$10 e %d notas de R$2\n", v50, v10, v2);
        }
        scan.close();
    }
}
