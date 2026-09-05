class Solution {
    public int pivotIndex(int[] nums) {
        int prefix_sum=0;
        int total=0;
        for(int i=0;i<nums.length;i++)
        {
            total+=nums[i];
        }
        for(int i=0;i<nums.length;i++)
        {
            if(total-prefix_sum-nums[i]==prefix_sum)
            {
                return i;
            }
            prefix_sum+=nums[i];  
        }
        return -1;
    }
}