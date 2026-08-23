int minSubArrayLen(int target, int* nums, int numsSize) {
        int i=0;
        int j=0;
        int sum=0;
        int minn=INT_MAX;
        while(j<numsSize)
        {
            sum+=nums[j];
            while(sum>=target)
            {
                minn=MIN(j-i+1,minn);
                sum-=nums[i];
                i++;
            }
            j++;
        }
        return (minn==INT_MAX)?0:minn;
}