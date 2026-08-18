int missingNumber(int* nums, int numsSize) {
        int freq[numsSize+1];
        memset(freq,0,sizeof(freq));
        for(int i=0;i<numsSize;i++)
        {
            freq[nums[i]]++;
        }
        for(int i=0;i<=numsSize;i++)
        {
            if(freq[i]==0)
            {
                return i;
            }
        }
        return -1;
}