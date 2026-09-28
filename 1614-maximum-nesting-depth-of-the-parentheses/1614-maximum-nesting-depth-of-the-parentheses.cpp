class Solution {
public:
    int maxDepth(string s) {
        int count=0;
        int maxi=0;
        for(char i:s)
        {
            if(i=='(')
            {
                count+=1;
                maxi=max(count,maxi);
            }
            else if(i==')')
            {
                count-=1;
            }
        }
        return maxi;
    }
};