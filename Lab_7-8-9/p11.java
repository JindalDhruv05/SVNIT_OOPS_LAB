import java.util.HashSet;
import java.util.Scanner;

public class p11{

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter a string: ");
        String input = scanner.nextLine();

        if (check(input)) {
            System.out.println("The string is a perfect string.");
        } else {
            System.out.println("The string is not a perfect string.");
        }

        scanner.close();
    }

    public static boolean check(String str) {
        HashSet<Character> charSet = new HashSet<>();

        for (char ch : str.toCharArray()) {
            if (charSet.contains(ch)) {
                return false;
            }
            charSet.add(ch);
        }

        return true;
    }
}
