    int solve(int n, int mem[])
    {
        if(n<=2)
        {
            return n;
        }
        if(mem[n]!=-1)
        {
            return mem[n];
        }
        return mem[n]=solve(n-1, mem)+solve(n-2, mem);
    }

int climbStairs(int n) {
    int mem[n+1];
    memset(mem, -1, sizeof(mem));
    return solve(n, mem);
}