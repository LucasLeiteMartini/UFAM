import java.util.Scanner;

public class RotaOrtodromica {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        double t1 = scan.nextDouble();
        double g1 = scan.nextDouble();
        double t2 = scan.nextDouble();
        double g2 = scan.nextDouble();
        
        int r = 6371;

        double radT1 = Math.toRadians(t1);
        double radG1 = Math.toRadians(g1);
        double radT2 = Math.toRadians(t2);
        double radG2 = Math.toRadians(g2);

        double d = r * Math.acos((Math.sin(radT1) * Math.sin(radT2)) + ((Math.cos(radT1) * Math.cos(radT2)) * Math.cos(radG1 - radG2)));

        System.out.printf("A distancia entre os pontos (%.6f, %.6f) e (%.6f, %.6f) e de %.2f km\nS", t1, g1, t2, g2, d);


    scan.close();
    }
}
