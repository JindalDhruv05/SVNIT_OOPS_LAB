import java.util.Scanner;

class P1{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter miles driven per day: ");
        float miles = sc.nextFloat();
        System.out.println("Enter cost per gallon of gasoline : ");
        float price = sc.nextFloat();
        System.out.println("Enter the average gallons per mile of car: ");
        float avg = sc.nextFloat();
        System.out.println("Enter average fees per day: ");
        float fees = sc.nextFloat();
        System.out.println("Enter tolls per day: ");
        float tolls = sc.nextFloat();
        float total_cost = (avg*price*miles) + fees + tolls;
        System.out.println("Total cost is "+total_cost);
    }
}