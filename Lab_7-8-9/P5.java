import java.util.Scanner;

public class P5{
    public static void main(String []args){
        Scanner sc = new Scanner(System.in);
        float avg = 0;

        System.out.print("Enter the number of trips: ");
        int n = sc.nextInt();
        for(int i=0;i<n;i++){
            System.out.print("Enter miles driven: ");
            float miles = sc.nextFloat();
            System.out.print("Enter gallons of fuel used: ");
            float fuel = sc.nextFloat();
            avg = avg + (miles/fuel);
        }
        System.out.println("Average miles per gallon used is " + (avg/n));
    }
}