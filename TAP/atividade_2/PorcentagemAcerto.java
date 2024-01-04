import java.util.ArrayList;
import java.util.Scanner;

public class PorcentagemAcerto {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        
        ArrayList<Integer> resposta = new ArrayList<>();
        ArrayList<Integer> gabarito = new ArrayList<>();
        
        //Escaneia os valores para a resposta
        int resp = scan.nextInt();        
        while(resp != -1){
            resposta.add(resp);
            resp = scan.nextInt();
        }

        //Escaneia os valores para o gabarito
        int gab = scan.nextInt();
        while(gab != -1){
            gabarito.add(gab);
            gab = scan.nextInt();
        }
        
        // Contabiliza a quantidade de acertos
        double acertos = 0.0;
        for(int i = 0; i < resposta.size(); i++){
            if(resposta.get(i) == gabarito.get(i)){
                acertos++;
            }
        }

        // Calcula e imprime a porcentagem de acertos
        double porcentagem = (acertos/gabarito.size()) * 100;
        System.out.printf("%.2f\n", porcentagem);

        scan.close();
    }
}
