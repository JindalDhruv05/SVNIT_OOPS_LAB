class Date{
    private int day, month, year;
    Date(int _day, int _month, int _year){
        set(_day,_month,_year);
    }
    void set(int _day, int _month, int _year){
        day=_day;
        month=_month;
        year=_year;
    }
    void get(){
        System.out.println("Day: " + day);
        System.out.println("Month: " + month);
        System.out.println("Year: "+ year);
    }
    void displayDate(){
        System.out.println("Date: "+day+"/"+month+"/"+year);
    }
}

public class P4{
    public static void main(String[] args){
        Date d1 = new Date(12,4,2024);
        d1.get();
        d1.displayDate();
    }
}
