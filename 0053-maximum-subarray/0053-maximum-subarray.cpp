class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_sum=INT_MIN;
        int n=nums.size();
        int cur_sum=0;
        for(int i=0;i<n;i++)
        {
            
                cur_sum+=nums[i];
                if(cur_sum>max_sum)
                {
                    max_sum=cur_sum;
                }
                if(cur_sum<0)
                {
                    cur_sum=0;
                }
        }
        return max_sum;
    }
};