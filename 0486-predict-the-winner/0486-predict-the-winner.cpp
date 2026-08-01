class Solution {
public:
    bool predictTheWinner(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(nums.begin(),nums.end());
        for(int i=2;i<n+1;i++)
        {
            for(int j=0;j<n-i+1;j++)
            {
                int k=j+i-1;
                dp[j]=max(nums[j]-dp[j+1],nums[k]-dp[j]);
            }
        }
        return dp[0]>=0;
    }
};