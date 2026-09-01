class Solution {
    private boolean solve(int n, int i)
    {
        if(Math.pow(2,i)==n)
        {
            return true;
        }
        if(Math.pow(2,i)>n)
        {
            return false;
        }
        return solve(n,i+1);
    }

    public boolean isPowerOfTwo(int n) {
        if(n<=0)
        {
            return false;
        }
        return solve(n,0);
    }
}