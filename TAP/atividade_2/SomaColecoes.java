import java.util.Scanner;

public class SomaColecoes {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        boolean flag = true;

        int a = scan.nextInt();
        int soma = 0;
        while(flag){
            if(a != -1){
                soma += a;
                a = scan.nextInt();
            }else if(a == -1 && soma != 0){
                System.out.printf("%d\n", soma);
                soma = 0;
                a = scan.nextInt();
            }else{
                flag = false;
            }
        }
    scan.close();
    }
}
