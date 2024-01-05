import java.util.Scanner;

public class CifraCesar {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        
        int k = scan.nextInt();

        String originalString = scan.nextLine().trim();

        System.out.print(encrypString(originalString, k));

    scan.close();
    }

    public static String encrypString(String text, int desloc){
        StringBuilder encryptedBuilder = new StringBuilder();

        for(int i = 0; i < text.length(); i++){
            char character = text.charAt(i);

            if(Character.isLetter(character)){
                char newCharacter = (char) ('A' + (Character.toUpperCase(character) - 'A' + desloc) % 26);
                encryptedBuilder.append(Character.toUpperCase(newCharacter));
            }else{
                encryptedBuilder.append(character);
            }

        }

        return encryptedBuilder.toString(); 

    }

}
