class Solution {
    public int waysToSplitArray(int[] nums) {
        long prefix_sum=0;
        long suffix_sum=0;
        long total=0;
        for(int i=0;i<nums.length;i++)
        {
            total+=nums[i];
        }
        int count=0;
        for(int i=0;i<nums.length-1;i++)
        {
            prefix_sum+=nums[i];
            suffix_sum=total-prefix_sum;
            if(prefix_sum>=suffix_sum)
            {
                count+=1;
            }
        }
        return count;
    }
}