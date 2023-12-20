import java.util.Scanner;

class ParImpar{
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        
        int a  = scan.nextInt();
        while( a != -1){

            if(a % 2 == 0){
                System.out.println("PAR");
            } else{
                System.out.println("IMPAR");
            }

            a = scan.nextInt();

        }
        
        scan.close();
    }
}