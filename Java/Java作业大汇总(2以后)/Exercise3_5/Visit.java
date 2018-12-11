package Exercise3_5;

import java.util.Date;

public class Visit {
    protected Customer customer;
    protected Date date;
    protected double serviceExpense;
    protected double productExpense;
    Visit(String name,Date date){
        customer=new Customer(name);
        this.date=date;
    }
    public String getName(){
        return customer.getName();
    }
    public double getServiceExpense(){
        return serviceExpense;
    }
    public void setServiceExpense(double s){
        serviceExpense=s;
    }
    public double getProductExpense(){
        return productExpense;
    }
    public void setProductExpense(double s){
        productExpense=s;
    }
    public double getTotalExpense(){
        return productExpense+serviceExpense;
    }
    public void BuyProduct(double x,DiscountRate ds){
        if(customer.member){
            productExpense+=x*(1-ds.getProductDiscountRate(customer.getMemberType()));
        }
        else{
            productExpense+=x;
        }
    }
    public void BuyService(double y,DiscountRate ds){
        if(customer.member){
            serviceExpense+=y*(1-ds.getServiceDiscountRate(customer.memberType));
        }
        else{
            productExpense+=y;
        }
    }

    @Override
    public String toString() {
        return customer.toString()+"    "+date.toString()+"   ServiceExpense"+serviceExpense+"     ProductExpense"+productExpense;
    }
}
