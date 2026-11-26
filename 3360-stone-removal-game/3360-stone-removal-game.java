class Solution {
    public boolean canAliceWin(int n) {
        if(n<10)
        {
            return false;
        }
        int turn=10;
        boolean alice=true;
        while(n>=turn)
        {
            n-=turn;
            turn--;
            alice=!alice;
        }
        return !alice;
    }
}