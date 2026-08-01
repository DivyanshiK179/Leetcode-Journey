class Solution {
    public boolean predictTheWinner(int[] nums) {
        int n=nums.length;
        int[] dp=new int[n];
        for(int i=0;i<n;i++)
        {
            dp[i]=nums[i];
        }
        for(int i=2;i<n+1;i++)
        {
            for(int j=0;j<n-i+1;j++)
            {
                int k=j+i-1;
                dp[j]=Math.max(nums[j]-dp[j+1],nums[k]-dp[j]);
            }
        }
        return dp[0]>=0;
    }
}