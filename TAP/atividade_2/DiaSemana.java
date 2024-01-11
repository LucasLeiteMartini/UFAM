import java.util.ArrayList;
import java.util.Scanner;


public class DiaSemana{
    public static void main(String[] args) {
        ArrayList<Integer> workLoadArrayList = new ArrayList<>();
        Scanner scan = new Scanner(System.in);

        int a;

        while((a  = scan.nextInt()) != -1){
            workLoadArrayList.add(a);
        }
        
        int tot = workLoadArrayList.size() / 7;

        int[][] employeeMatrix = new int[tot][7];

        for(int i = 0; i < tot; i++){
            for(int j = 0; j < 7; j++){
                employeeMatrix[i][j] = workLoadArrayList.get((i*7) + j);
            }
        }

        int dailyWorkload;

        workLoadArrayList = new ArrayList<>();

        for(int j = 0; j < 7; j++){
            dailyWorkload = 0;
            for(int i = 0; i < tot; i++){
                dailyWorkload += employeeMatrix[i][j];
            }
            workLoadArrayList.add(dailyWorkload);
        }

        dailyWorkload = workLoadArrayList.get(0);

        for(int i = 0; i < workLoadArrayList.size(); i++){
            dailyWorkload = Math.max(dailyWorkload, workLoadArrayList.get(i));
        }

        for(int i = 0; i < workLoadArrayList.size(); i++){
            if(workLoadArrayList.get(i) == dailyWorkload){
                System.out.println(i+1);
            }
        }

scan.close();
    }
}