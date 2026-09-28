class Solution {
    public int maxDepth(String s) {
        int count=0;
        int maxi=0;
        for(char i:s.toCharArray())
        {
            if(i=='(')
            {
                count+=1;
                maxi=Math.max(count,maxi);
            }
            else if(i==')')
            {
                count-=1;
            }
        }
        return maxi;
    }
}