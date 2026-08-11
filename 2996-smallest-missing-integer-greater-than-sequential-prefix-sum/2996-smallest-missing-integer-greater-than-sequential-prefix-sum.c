int missingInteger(int* nums, int numsSize) {
        int sum=nums[0];
        for(int i=1;i<numsSize;i++)
        {
            if(nums[i]==nums[i-1]+1)
            {
                sum+=nums[i];
            }
            else
            {
                break;
            }
        }
        bool exist[51]={false};
        for(int i=0;i<numsSize;i++)
        {
            exist[nums[i]]=true;
        }
        while(sum<=50 && exist[sum])
        {
            sum++;
        }
        return sum;
}