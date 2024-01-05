import java.util.Scanner;

public class VolumeCombustivel {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        
        int tankHeight = scan.nextInt();
        int gasHeight = scan.nextInt();
        int r = scan.nextInt();
    
        double vol = 0.0;
        double vol2 = 0.0;
        double volCylidenr = 0.0;
        double vol3 = 0.0;


        if( r == 0 || r < 0 || tankHeight == 0 || tankHeight < 0){
            System.out.print(-1.000);
        }else{
            if(gasHeight < r){
                vol = ((Math.PI/3.0) * Math.pow(gasHeight, 2)) * (3.0*r - gasHeight);
                System.out.printf("%.3f\n", vol);
            }else if(gasHeight == r){
                vol = ((4.0/3.0) * (Math.PI * Math.pow(r, 3))) / 2;
                System.out.printf("%.3f\n", vol);
            }else if(r < gasHeight && gasHeight < tankHeight){
                vol2 = ((4.0/3.0) * (Math.PI * Math.pow(r, 3))) / 2;
                volCylidenr = Math.PI * Math.pow(r, 2) * (gasHeight - r);
                vol = vol2 + volCylidenr;
                System.out.printf("%.3f\n", vol);
            }else if (gasHeight == tankHeight) {
                vol2 = (4.0/3.0) * (Math.PI * Math.pow(r, 3));
                volCylidenr = Math.PI * Math.pow(r, 2) * (gasHeight - (r*2));
                vol = vol2 + volCylidenr;
                System.out.printf("%.3f\n", vol);
            }else{
                vol3 = ((Math.PI/3.0) * Math.pow(gasHeight, 2)) * (3.0*r - (tankHeight - gasHeight));
                vol2 = (4.0/3.0) * (Math.PI * Math.pow(r, 3));
                volCylidenr = Math.PI * Math.pow(r, 2) * (gasHeight - (r*2));
                vol = (vol2 + volCylidenr) - vol3;
            }
        }
    
    
    


    scan.close();
    }
}