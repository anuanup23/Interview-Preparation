package Leetcode.Examples;
import java.util.List;
//public class BillingSystem {
//
//}
public class BillingSystem{
    User user;
    List<Items> items;
    Payment payment;
    
    public void createUser(User user){
        // check if user is already there or not, if user is already created then we will use existing userId
    }
    
    public float createBill(User user,List<Items> items){
        float total=0;
        for(int i=0;i<items.size();i++){
            total+=(items.get(i).price)*(items.get(i).quantity);
        }
        return total;
    }
}

class User {
    int id;
    String Name;
    int phoneNo;
}

class Items{
    int id;
    Category category;
    float price;
    int quantity;
}

enum Category{
    KIDS,SPORTS,PANTRY;
}

class Payment{
    PaymentType type;
    PaymentStatus status;
    public boolean doPayment(PaymentType typeOfPayment){
        return true;
    }
}

enum PaymentStatus{
    DONE,PENDING
}

enum PaymentType{
    CASH,UPI,DEBIT_CARD,CREDIT_CARD
}