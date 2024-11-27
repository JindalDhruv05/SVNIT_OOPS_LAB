import java.util.Arrays;

interface Function{
    int evaluate(int x);
}

class Half implements Function{
    public int evaluate(int x){
        return x/2;
    }
}

class P13{

    static int[] solve(int[] ary){
        int n=ary.length;
        int[] temp = new int[n];
        for(int i=0;i<n;i++){
            Half x = new Half();
            temp[i] = x.evaluate(ary[i]);
        }
        return temp;
    }

    public static void main(String[] args){
        int[] ary = {1,2,3};
        int[] new_ary = solve(ary);
        for(int i:new_ary){
            System.out.println(i);
        }
    }
}