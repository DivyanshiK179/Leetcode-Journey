class Solution {
public:
    int smallestNumber(int n, int t) {
        int i;
        for(i=n;i<n+10;i++)
        {
            int prod=1;
            int temp=i;
            while(temp>0)
            {
                int dig=temp%10;
                prod*=dig;
                temp=temp/10;
            }
            if(prod%t==0)
            {
                break;
            }
        }
        return i;
    }
};