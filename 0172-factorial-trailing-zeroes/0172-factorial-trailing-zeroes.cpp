class Solution {
public:
    int trailingZeroes(int n) {
        int count=0;
        unsigned long long fact=1;
        for(int i=2;i<=n;i++)
        {
            fact*=i;
            while(fact%10==0)
            {
                count++;
                fact/=10;
            }
            fact%=10000000000ULL;
        }
        return count;
    }
};