bool predictTheWinner(int* nums, int numsSize) {
        int n=numsSize;
        int *dp=(int*)malloc(n*sizeof(int));
        for(int i=0;i<n;i++)
        {
            dp[i]=nums[i];
        }
        for(int i=2;i<n+1;i++)
        {
            for(int j=0;j<n-i+1;j++)
            {
                int k=j+i-1;
                dp[j]=MAX(nums[j]-dp[j+1],nums[k]-dp[j]);
            }
        }
        return dp[0]>=0;
}