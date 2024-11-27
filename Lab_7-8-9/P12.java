import java.util.Scanner;

public class P12{

    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter a: ");
        int a = sc.nextInt();
        System.out.print("Enter b: ");
        int b = sc.nextInt();

        System.out.print("Enter pattern: ");
        String pattern = sc.next();

        int count = countPatternOccurrences(a,b,pattern);
        System.out.println("The pattern \"" + pattern + "\" occurred " + count + " times between " + a + " and " + b + ".");
    }

    public static int countPatternOccurrences(int a, int b, String pattern){
        int count = 0;
        if(a>b){
            int temp = a;
            a = b;
            b = temp;
        }

        for(int i=a;i<=b;i++){
            if(String.valueOf(i).contains(pattern)){
                count++;
            }
        }
        return count;
    }
}
