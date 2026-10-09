class Solution {
    public int minInsertions(String s) {
        int insertions=0;
        int open_needed=0;
        int i=0;
        int n=s.length();
        
        while(i<n)
        {
            if(s.charAt(i)=='(')
            {
                open_needed+=1;
                i+=1;
            }
            else
            {
                if(i+1<n && s.charAt(i+1)==')')
                {
                    i+=2;
                }
                else
                {
                    insertions+=1;
                    i+=1;
                }
                if(open_needed>0)
                {
                    open_needed-=1;
                }
                else
                {
                    insertions+=1;
                }
            }
        }

        insertions+=open_needed*2;
        return insertions;
    }
}