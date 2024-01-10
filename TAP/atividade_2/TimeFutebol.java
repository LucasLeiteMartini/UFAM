import java.util.ArrayList;
import java.util.Scanner;

public class TimeFutebol {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        ArrayList<Integer> allyArrayList = new ArrayList<>();
        ArrayList<Integer> enemyArrayList = new ArrayList<>();

        int win = 0, loss = 0, draw = 0, ally, enemy;

        while((ally = scan.nextInt()) != -1){
            allyArrayList.add(ally);
        }

        while((enemy = scan.nextInt()) != -1){
            enemyArrayList.add(enemy);
        }

        for(int i = 0; i < allyArrayList.size(); i++){
            if(allyArrayList.get(i) > enemyArrayList.get(i)){
                win++;
            }else if(allyArrayList.get(i) < enemyArrayList.get(i)){
                loss++;
            }else{
                draw++;
            }
        }

        System.out.printf("%d %d %d\n", win, draw, loss);
    
    scan.close();
    }
}
