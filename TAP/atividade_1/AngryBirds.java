import java.util.Locale;
import java.util.Scanner;

class AngryBirds{
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in).useLocale(Locale.US);

        int vo = scan.nextInt();
        double ang = scan.nextDouble();
        double d = scan.nextDouble();
        double g = 9.8;
        double r = 0.0;

        vo = (int) Math.abs(Math.pow(vo, 2));
        
        r = (vo * Math.sin(2*Math.toRadians(ang)))/g;

        if (d - r >= 0.2){
            System.out.print(0);
        }else{
            System.out.print(1);
        }

    scan.close();
    }
}