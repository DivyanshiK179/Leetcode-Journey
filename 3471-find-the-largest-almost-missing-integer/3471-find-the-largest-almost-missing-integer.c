int largestInteger(int* nums, int numsSize, int k) {
        int subarray_count[51]={0};
        int freq[51]={0};
        int i=0;
        int j=0;
        int maxi=-1;
        while(j<numsSize)
        {
            freq[nums[j]]++;
            if(j-i+1==k)
            {
                for(int c=0;c<51;c++)
                {
                    if(freq[c]>0)
                    {
                        subarray_count[c]++;
                    }
                }
                freq[nums[i]]--;
                i++;
            }
            j++;
        }
        for(int d=0;d<51;d++)
        {
            if(subarray_count[d]==1)
            {
                maxi=MAX(maxi,d);
            }
        }
        return maxi;
}