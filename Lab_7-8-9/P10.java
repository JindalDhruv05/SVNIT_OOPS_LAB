import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

class P10{
    static void check(String s, int n){
        Map<Character,Integer> frequencyMap = new HashMap<>();
        for(int i=0;i<s.length();i++){
            char cur = s.charAt(i);
            frequencyMap.put(cur,frequencyMap.getOrDefault(cur,0) + 1);
        }

        for(Map.Entry<Character,Integer> entry : frequencyMap.entrySet()){
            if(entry.getValue()>n){
                System.out.println(entry.getKey()+"-"+entry.getValue());
            }
        }
    }

    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter String: ");
        String s = sc.nextLine();
        System.out.print("Enter n: ");
        int n = sc.nextInt();
        check(s,n);
    }
}
