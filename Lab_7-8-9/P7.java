import java.util.Random;

public class P7{
    private enum status{CONTINUE, WON, LOST};
    private static final Random randomNumbers = new Random();
    public static void main(String[] args) {
        int sumOfDice = roll();
        status gameStatus;
        int points = 0;

        switch(sumOfDice){
            case 7:
            case 11:
                gameStatus = status.WON;
                break;
            case 2:
            case 3:
            case 12:
                gameStatus = status.LOST;
                break;
            default:
                gameStatus = status.CONTINUE;
                points = sumOfDice;
                System.out.println("Point is set to: " + points);
                break;
        }
        while(gameStatus==status.CONTINUE){
            sumOfDice=roll();

            if(sumOfDice==points){
                gameStatus = status.WON;
            }
            else if(sumOfDice==7){
                gameStatus = status.LOST;
            }
        }
        if(gameStatus==status.WON){
            System.out.println("Player won!");
        }
        else{
            System.out.println("Player lost!");
        }
    }
    public static int roll(){
        int dice1 = 1+randomNumbers.nextInt(6);
        int dice2 = 1+randomNumbers.nextInt(6);
        int sum = dice1+dice2;

        System.out.println("Player rolled: "+dice1+"+"+dice2+"="+sum);
        return sum;
    }
}
