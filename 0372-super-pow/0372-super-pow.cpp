class Solution {

private:
long long power(long long base,long long exp, long long mod)
{
    long long res=1;
    while(exp>0)
    {
        if(exp%2==1)
        {
            res=(res*base)%mod;
        }
        base=(base*base)%mod;
        exp/=2;
    }
    return res;
}

public:
    int superPow(int a, vector<int>& b) {
        long long r=0;
        for(int i:b)
        {
            r=(r*10+i)%1140;
        }
        if(r==0)
        {
            r=1140;
        }
        return power(a,r,1337);
    }
};