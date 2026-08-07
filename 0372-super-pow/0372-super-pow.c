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

int superPow(int a, int* b, int bSize) 
{
    long long r=0;
    for(int i=0;i<bSize;i++)
    {
        r=(r*10+b[i])%1140;
    }
    if(r==0)
    {
        r=1140;
    }
    return (int)power(a,r,1337);
}