package com.company;

public class MyDate {
    private int year;
    private int month;
    private int day;
    MyDate(int a,int b,int c){
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
        Res+=strDays[getDayOfWeek(year,month,day)+1];
        Res+=" ";
        Res+=String.valueOf(day);
        Res+=" ";
        Res+=strMonth[month];
        Res+=" ";
        Res+=String.valueOf(year);
        return Res;
    }

    public static int getDayOfWeek(int year,int month,int day){
        return ((day+2*month+3*(month+1))/5+year+year/4-year/100+year/400)%7;
    }

    public void nextDay(){
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
    }

    public void nextMonth(){
        month++;
        if(month>12){
            month%=12;
            nextYear();
        }
    }

    public void nextYear(){
        year++;
    }
}
