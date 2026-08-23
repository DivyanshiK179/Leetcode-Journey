class Solution {
    public int minSubArrayLen(int target, int[] nums) {
        int i=0;
        int j=0;
        int sum=0;
        int minn=Integer.MAX_VALUE;
        while(j<nums.length)
        {
            sum+=nums[j];
            while(sum>=target)
            {
                minn=Math.min(j-i+1,minn);
                sum-=nums[i];
                i++;
            }
            j++;
        }
        return (minn==Integer.MAX_VALUE)?0:minn;
    }
}