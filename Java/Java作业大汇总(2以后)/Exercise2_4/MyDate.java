package Exercise2_4;

import Exercise2_1.MyInteger;

public class MyDate {
    private int year;
    private int month;
    private int day;
    MyDate(int a,int b,int c){
        if(!isValidDate(a,b,c))
            System.out.println("Invalid year,month,or day!");
        setDate(a,b,c);
    }
    private void setDate(int Year,int Month,int Day){
        setDay(Day);
        setYear(Year);
        setMonth(Month);
    }
    private void setYear(int Year){
        year=Year;
    }
    private void setMonth(int Month){
        month=Month;
    }
    private void setDay(int Day){
        day=Day;
    }

    public int getDay() {
        return day;
    }

    public int getMonth() {
        return month;
    }

    public int getYear() {
        return year;
    }

    private static String[] strMonth={"Empty","January","February","March","April","May","June","July","August",
            "September","October","November","December"};
    private static String[] strDays={"Empty","Monday","Tuesday","Wednesday","Thursday","Friday",
            "Saturday","Sunday"};
    private static String[] newDays={"Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday",};
    private static int [] dayInMonths={29,31,28,31,30,31,30,31,31,30,31,30,31};
    public static boolean isLeapYear(int year){
        return (year%400)==0||((year%4)==0&&(year%100)!=0);
    }
    public static boolean isValidDate(int year,int month,int day){
        if(year<1||year>9999||month<1||month>12)
            return false;
        if(isLeapYear(year)&&month==2){
            return day>0&&day<=dayInMonths[0];
        }
        else{
            return day>0&&day<=dayInMonths[month];
        }
    }

    public String toString(){
        String Res="";
        Res+=newDays[getDayOfWeek(year,month,day)];
        Res+=" ";
        Res+=String.valueOf(day);
        Res+=" ";
        Res+=strMonth[month];
        Res+=" ";
        Res+=String.valueOf(year);
        return Res;
    }

    public static int getDayOfWeek(int year,int month,int day){
        int x = year;
        int y = month;
        int z = day;
        if (month == 1) {
            y = 13;
            x = year - 1;
        }
        if (month == 2) {
            y = 14;
            x = year - 1;
        }
        return (z+2*y+3*(y+1)/5+x+x/4-x/100+x/400)%7;
    }

    public MyDate nextDay(){
        day++;
        if(isLeapYear(year)&&month==2){
            if(day>29){
                day=1;
                nextMonth();
            }
        }
        else{
            if(day>dayInMonths[month+1]){
                day=1;
                nextMonth();
            }
        }
        return new MyDate(this.year,this.month,this.day);
    }

    public MyDate previousDay(){
        day--;
        if(day==0){
            previousMonth();
            if(isLeapYear(year)&&month==2)
                day=29;
            else
                day=dayInMonths[month];
        }
        return new MyDate(year,month,day);
    }

    public MyDate previousMonth(){
        month--;
        if(month==0) {
            previousYear();
            month=12;
        }
        if(isLeapYear(year)&&month==2)
            day=29;
        else
            day=dayInMonths[month];
        return new MyDate(year,month,day);
    }

    public MyDate previousYear(){
        year--;
        if(isLeapYear(year)&&month==2)
            day=29;
        else
            day=dayInMonths[month];
        return new MyDate(year,month,day);
    }

    public MyDate nextMonth(){
        month++;
        if(month>12){
            month%=12;
            nextYear();
        }
        return new MyDate(year,month,day);
    }

    public MyDate nextYear(){
        year++;
        return new MyDate(year,month,day);
    }
    public static void main(String[] args){
        /*
        MyDate d1=new MyDate(2012,2,28);
        System.out.println(d1);
        System.out.println(d1.nextDay());
        System.out.println(d1.nextDay());
        System.out.println(d1.nextMonth());
        System.out.println(d1.nextYear());

        MyDate d2=new MyDate(2012,1,2);
        System.out.println(d2);
        System.out.println(d2.previousDay());
        System.out.println(d2.previousDay());
        System.out.println(d2.previousMonth());
        System.out.println(d2.previousYear());

        MyDate d3=new MyDate(2012,2,29);
        System.out.println(d3.previousYear());

        MyDate d4=new MyDate(2099,11,31);
        MyDate d5=new MyDate(2011,2,29);
        */
    }

}