int longestMonotonicSubarray(int* nums, int numsSize) {
        int maxlen=1;
        int icount=1;
        int dcount=1;
        for(int i=0;i<numsSize-1;i++)
        {
            if(nums[i]<nums[i+1])
            {
                icount+=1;
                dcount=1;
            }
            else if(nums[i]>nums[i+1])
            {
                dcount+=1;
                icount=1;
            }
            else
            {
                icount=1;
                dcount=1;
            }
            int curmax=(icount>dcount)?icount:dcount;
            if(curmax>maxlen)
            {
                maxlen=curmax;
            }
        }
        return maxlen;
}