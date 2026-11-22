class Solution {
    public boolean checkString(String s) {
        boolean seenb=false;
        for(char i:s.toCharArray())
        {
            if(i=='b')
            {
                seenb=true;
            }
            else if(seenb)
            {
                return false;
            }
        }
        return true; 
    }
}