int waysToSplitArray(int* nums, int numsSize) {
        long long prefix_sum=0;
        long long suffix_sum=0;
        long long total=0;
        for(int i=0;i<numsSize;i++)
        {
            total+=nums[i];
        }
        int count=0;
        for(int i=0;i<numsSize-1;i++)
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