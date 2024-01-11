import java.util.Scanner;

public class DistanciaAviao{
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        
        int[][] planeTravelTime = {
            {0, 2, 11, 6, 15, 11, 1},
            {2, 0, 7, 12, 4, 2, 15},
            {11, 7, 0, 11, 8, 3, 13},
            {6, 12, 11, 0, 10, 2, 1},
            {15, 4, 8, 10, 0, 5, 13},
            {11, 2, 3, 2, 5, 0, 14},
            {1, 15, 13, 1, 13, 14, 0}
        };

        int a = scan.nextInt();
        int atual = a;
        int soma = 0;

        while((a = scan.nextInt()) != -1){
            
            int index = (a/111) - 1;
            int index_atual = (atual/111) - 1;
                        
            soma += planeTravelTime[index_atual][index];                           
            atual = a;
        }

        System.out.printf("%d\n", soma);

    scan.close();
    }
}