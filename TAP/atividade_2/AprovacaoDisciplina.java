import java.util.ArrayList;
import java.util.Locale;
import java.util.Scanner;

public class AprovacaoDisciplina {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in).useLocale(Locale.US);
        ArrayList<Double> gradeArrayList = new ArrayList<>();
        ArrayList<Integer> frequencyArrayList = new ArrayList<>();

        int approved = 0, disapproved_grade = 0, disapproved_frequency = 0;

        int frequency, workload;
        double grade;

        while((grade = scan.nextDouble()) != -1){
            gradeArrayList.add(grade);
        }

        while((frequency = scan.nextInt()) != -1){
            frequencyArrayList.add(frequency);
        }

        workload = scan.nextInt();

        for(int i = 0; i < gradeArrayList.size(); i++){
            if(frequencyArrayList.get(i) < (workload * 0.75)){
                disapproved_frequency++;
            }else if(frequencyArrayList.get(i) > (workload * 0.75) && gradeArrayList.get(i) < 5.0){
                disapproved_grade++;
            }else{
                approved++;
            }
        }

        System.out.printf("%d %d %d\n", approved, disapproved_grade, disapproved_frequency);
        
    scan.close();
    }
}
