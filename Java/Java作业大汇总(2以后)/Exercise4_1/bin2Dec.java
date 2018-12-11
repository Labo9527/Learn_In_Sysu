package Exercise4_1;

public class bin2Dec {
    public bin2Dec(){

    }
    public static int convert(String binary){
        try {
            int Res = 0;
            for (int i = 0; i < binary.length(); i++) {
                Res *= 2;
                if (binary.charAt(i) == '0') {
                    Res += 0;
                } else if (binary.charAt(i) == '1') {
                    Res += 1;
                } else {
                    throw new NumberFormatException("1");
                }
            }
            return Res;
        }
        catch (NumberFormatException e) {
            e.printStackTrace();
        }
        return -1;
    }
    public static void main(String[] args){
        System.out.println(convert("01001"));
        System.out.println(convert("123"));
    }
}
