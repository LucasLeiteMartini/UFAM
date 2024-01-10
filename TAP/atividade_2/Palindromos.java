import java.util.Scanner;

public class Palindromos {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        String originalString = scan.nextLine();
        String uperString = originalString.toUpperCase().replace(" ", "");
        String reversedString = reverseString(uperString);

        boolean flag = true;

        for(int i = 0; i < uperString.length(); i++){
            if(reversedString.charAt(i) != uperString.charAt(i)){
                flag = false;
                break;
            }
        }

        if(flag){
            System.out.println(uperString + " 1");
        }else{
            System.out.println(uperString + " 0");
        }
scan.close();
    }

    public static String reverseString(String originalString){
        StringBuilder reversed = new StringBuilder(originalString);
        return reversed.reverse().toString();
    }

}
