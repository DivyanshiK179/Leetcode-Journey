    bool solve(int n, int i)
    {
        if(pow(2,i)==n)
        {
            return true;
        }
        if(pow(2,i)>n)
        {
            return false;
        }
        return solve(n,i+1);
    }

bool isPowerOfTwo(int n) {
    if(n<=0)
    {
        return false;
    }
    return solve(n,0);
}