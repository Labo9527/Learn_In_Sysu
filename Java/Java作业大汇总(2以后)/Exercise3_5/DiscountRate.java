package Exercise3_5;

public class DiscountRate {
    static double serviceDiscountPremium=0.2;
    static double serviceDiscountGold=0.15;
    static double serviceDiscountSilver=0.1;

    static double productDiscountPremium=0.1;
    static double productDiscountGold=0.1;
    static double productDiscountSilver=0.1;

    double getServiceDiscountRate(String type){
        if(type=="Premium")
            return serviceDiscountPremium;
        else if(type=="Gold")
            return serviceDiscountGold;
        else if(type=="Silver")
            return serviceDiscountSilver;
        return 0;
    }

    double getProductDiscountRate(String type){
        if(type=="Premium")
            return productDiscountPremium;
        else if(type=="Gold")
            return productDiscountGold;
        else if(type=="Silver")
            return productDiscountSilver;
        return 0;
    }

}
