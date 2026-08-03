int findMaxConsecutiveOnes(int* nums, int numsSize) {
        int cur_count=0;
        int max_count=0;
        for(int i=0;i<numsSize;i++)
        {
            if(nums[i]==1)
            {
                cur_count+=1;
                max_count=MAX(cur_count,max_count);
            }
            else
            {
                cur_count=0;
            }
        }
        return max_count;
}