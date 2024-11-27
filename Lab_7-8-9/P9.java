import java.util.Scanner;

class P9{
    static boolean check(String s){
        if(!s.toLowerCase().equals(s)){
            return false;
        }
        boolean flag=true;
        for(int i=0;i<10;i++){
            if(s.contains(String.valueOf(i))){
                flag=false;
            }
        }
        if(flag){
            return false;
        }
        flag=false;
        for(int i=0;i<s.length();i++){
            if(!Character.isDigit(s.charAt(i)) && !Character.isLetter(s.charAt(i)) && !Character.isWhitespace(s.charAt(i))){
                flag=true;
            }
        }
        if(flag){
            return false;
        }
        if(s.length()<5 || s.length()>12){
            return false;
        }
        for(int i=0;i<s.length()-1;i++){
            for(int len=1;i+2*len<=s.length();len++){
                String firstPart = s.substring(i,i+len);
                String secondPart = s.substring(i+len,i+2*len);
                if (firstPart.equals(secondPart)){
                    return false;
                }
            }
        }
        return true;
    }
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter String: ");
        String s = sc.nextLine();
        System.out.println(check(s));
    }
}