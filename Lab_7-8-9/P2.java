class Invoice{
    private String part_number, description;
    private int qty;
    private double price;
    Invoice(String _no, String _desc, int _qty, double _price){
        set(_no,_desc,_qty,_price);
    }
    void set(String _no, String _desc, int _qty, double _price){
        part_number = _no;
        description = _desc;
        qty = _qty>0 ? _qty : 0;
        price = _price>0 ? _price : 0;
    }
    void get(){
        System.out.println("Part Number : " + part_number);
        System.out.println("Description: " + description);
        System.out.println("Quantity: " + qty);
        System.out.println("Price per item: " + price);
    }
    double getInvoiceAmount(){
        return qty*price;
    }
}

class P2{
    public static void main(String[] args){
        Invoice i1 = new Invoice("10","Steel",10,5000);
        i1.get();
        System.out.println("Invoice amount is: "+i1.getInvoiceAmount());
    }
}