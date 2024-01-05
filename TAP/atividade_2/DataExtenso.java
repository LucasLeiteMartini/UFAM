import java.util.Scanner;

public class DataExtenso {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        String[] meses = new String[12];

        meses[0] = "janeiro";
        meses[1] = "fevereiro";
        meses[2] = "março";
        meses[3] = "abril";
        meses[4] = "maio";
        meses[5] = "junho";
        meses[6] = "julho";
        meses[7] = "agosto";
        meses[8] = "setembro";
        meses[9] = "outubro";
        meses[10] = "novembro";
        meses[11] = "dezembro";


        int data = scan.nextInt();

        int ano = data % 10000;
        data /= 10000;
        int mes = data % 100;
        data /= 100;
        
        System.out.println(data + " de " + meses[mes-1] + " de " + ano);
    scan.close();
    }   
}
