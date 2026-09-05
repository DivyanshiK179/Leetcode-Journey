int findMiddleIndex(int* nums, int numsSize) {
        int prefix_sum=0;
        int total=0;
        for(int i=0;i<numsSize;i++)
        {
            total+=nums[i];
        }
        for(int i=0;i<numsSize;i++)
        {
            if(total-prefix_sum-nums[i]==prefix_sum)
            {
                return i;
            }
            prefix_sum+=nums[i];  
        }
        return -1;
}