class Solution {
    public int minAddToMakeValid(String s) {
        int open_count=0;
        int added=0;
        for(char ch:s.toCharArray())
        {
            if(ch=='(')
            {
                open_count+=1;
            }
            else
            {
                if(open_count>0)
                {
                    open_count-=1;
                }
                else
                {
                    added+=1;
                }   
            }
        }
        return added+open_count;
    }
}