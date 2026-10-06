class Solution {
public:
    int minAddToMakeValid(string s) {
        int open_count=0;
        int added=0;
        for(char ch:s)
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
};