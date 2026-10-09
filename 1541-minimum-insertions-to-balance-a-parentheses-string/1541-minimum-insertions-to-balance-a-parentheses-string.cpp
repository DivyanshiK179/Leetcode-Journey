class Solution {
public:
    int minInsertions(string s) {
        int insertions=0;
        int open_needed=0;
        int i=0;
        int n=s.size();
        
        while(i<n)
        {
            if(s[i]=='(')
            {
                open_needed+=1;
                i+=1;
            }
            else
            {
                if(i+1<n and s[i+1]==')')
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
};