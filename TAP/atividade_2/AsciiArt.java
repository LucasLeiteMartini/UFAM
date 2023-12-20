import java.util.Scanner;

public class AsciiArt {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        int size = scan.nextInt();

        for (int i = 0; i < size; i++) {
            // Imprimir asteriscos
            for (int j = 0; j < size - i; j++) {
                System.out.print("*");
            }

            // Imprimir espaços no meio
            for (int k = 0; k < 2 * i; k++) {
                System.out.print(" ");
            }

            // Imprimir asteriscos novamente
            for (int l = 0; l < size - i; l++) {
                System.out.print("*");
            }
            System.out.println();
            
        }

    scan.close();
    }
}
