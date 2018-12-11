package Exercise3_5;

import java.util.Date;

public class Test {
    public static void main(String[] args){
        Date d1=new Date(2000,1,1);
        Visit v1=new Visit("John",d1);
        DiscountRate ds1=new DiscountRate();
        v1.customer.setMember(true);
        v1.customer.setMemberType("Silver");
        System.out.println(ds1.getProductDiscountRate(v1.customer.getMemberType()));
        System.out.println(ds1.getServiceDiscountRate(v1.customer.getMemberType()));
        System.out.println(v1);
        v1.BuyProduct(100,ds1);
        v1.BuyService(120,ds1);
        System.out.println(v1.getProductExpense());
        System.out.println(v1.getServiceExpense());
        System.out.println(v1.getTotalExpense());
    }
}
