import java.util.Scanner;

public class P6{
    static String modelOfCategory(String s){
        switch(s){
            case "SUV":
                return "TATA SAFARI";
            case "SEDAN":
                return "TATA INDIGO";
            case "ECONOMY":
                return "TATA INDICA";
            case "MINI":
                return "TATA NANO";
            default:
                return "does not exist";
        }
    }

    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter Car Category: ");
        String s = sc.nextLine();
        System.out.println("\nRecommended car is " + modelOfCategory(s));
    }
}
