class Solution {
    public int maxSubArray(int[] nums) {
        int max_sum=Integer.MIN_VALUE;
        int n=nums.length;
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
}