import java.util.Scanner;

public class IdadeUfam {
    public static void main(String[] args) {

        Scanner scan = new Scanner(System.in);

        int idade = scan.nextInt();

        System.out.printf("A Ufam tem %d anos de fundacao", (idade - 1909));
    
    scan.close();
    }
}
