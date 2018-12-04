public class Chess {
    private char Type;
    Chess(char type){
        Type=type;
    }
    protected char getType(){
        return Type;
    }
    Chess(){
        Type='B';
    }
}
