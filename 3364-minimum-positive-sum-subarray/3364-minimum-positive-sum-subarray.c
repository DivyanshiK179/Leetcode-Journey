int minimumSumSubarray(int* nums, int numsSize, int l, int r) {
        int min_sum=-1;
        for(int len=l;len<=r;len++)
        {
            int i=0;
            int j=0;
            int cur_sum=0;
            while(j<numsSize)
            {
                cur_sum+=nums[j];
                if(j-i+1==len)
                {
                    if(cur_sum>0)
                    {
                        if(min_sum==-1||cur_sum<min_sum)
                        {
                            min_sum=cur_sum;
                        }
                    }
                    cur_sum-=nums[i];
                    i++;
                }
                j++;
            }
        }
        return min_sum;
}