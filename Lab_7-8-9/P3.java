class Employee{
    private String name, lname;
    private double salary;
    Employee(String _name, String _lname, double _salary){
        set(_name,_lname,_salary);
    }
    void set(String _name, String _lname, double _salary){
        name=_name;
        lname=_lname;
        salary = _salary>0 ? _salary : 0;
    }
    void get(){
        System.out.println("Name: " + name);
        System.out.println("Last Name: " + lname);
        System.out.println("Monthly Salary: " + salary);
    }
    void hikeSalary(){
        salary = 1.1*salary;
    }
    void getSalary(){
        System.out.println("Yearly Salary of " + name + " is: " + salary*12);
    }
}

public class P3{
    public static void main(String[] args){
        Employee e1 = new Employee("Dhruv", "Jindal",100000);
        Employee e2 = new Employee("Devanshu","Mangal",100000);
        e1.get();
        e2.get();
        e1.hikeSalary();
        e2.hikeSalary();
        e1.getSalary();
        e2.getSalary();
    }
}
