package Exercise3_5;

public class Customer {
    protected String name;
    protected boolean member;
    protected String memberType;

    Customer(String name){
        this.name=name;
        member=false;
    }

    String getName(){
        return this.name;
    }

    public boolean isMember() {
        return member;
    }

    public void setMember(boolean member) {
        this.member = member;
    }

    String getMemberType(){
        return memberType;
    }

    void setMemberType(String type){
        this.memberType=type;
    }
    public String toString(){
        String Res="";
        Res+="Name:"+name+"  isMember:"+member;
        if(member) {
            Res+="    MemberType:";
            Res += memberType;
        }
        return Res;
    }


}
