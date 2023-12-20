import java.util.Scanner;

public class Xadrez {

    public static void main(String[] args) {
        
        Scanner scan = new Scanner(System.in);

        int size = scan.nextInt();

        for(int i = 0; i < size; i++){
            for(int j = 0; j < size*2; j++){
                if(i % 2 == 0){
                    if(j % 2 == 0){
                        System.out.print("*");
                    }else{
                        System.out.print(" ");
                    }
                }else{
                    if(j % 2 != 0){
                        System.out.print("*");
                    }else{
                        System.out.print(" ");
                    }
                }
            }
            System.out.println("");
        }
    
        scan.close();
    }
    
}