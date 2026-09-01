class Solution {
    private int solve(int n, int[] mem)
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
    public int climbStairs(int n) {
        int[] mem=new int[n+1];
        Arrays.fill(mem, -1);
        return solve(n, mem);
    }
}