int firstStableIndex(int* nums, int numsSize, int k) {
        int n=numsSize;
        if(n==0)
        {
            return -1;
        }
        int *suffix_min=(int*)malloc(n*sizeof(int));
        suffix_min[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--)
        {
            suffix_min[i]=MIN(nums[i],suffix_min[i+1]);
        }
        int prefix_max=nums[0];
        for(int i=0;i<n;i++)
        {
            prefix_max=MAX(prefix_max,nums[i]);
            if((prefix_max-suffix_min[i])<=k)
            {
                return i;
            }
        }
        return -1;
}