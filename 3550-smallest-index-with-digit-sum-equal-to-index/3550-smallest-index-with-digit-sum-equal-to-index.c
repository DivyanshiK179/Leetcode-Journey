int smallestIndex(int* nums, int numsSize) {
        for(int i=0;i<numsSize;i++)
        {
            int sum=0;
            int n=nums[i];
            while(n>0)
            {
                int dig=n%10;
                sum+=dig;
                n=n/10;
            }
            if(sum==i)
            {
                return i;
            }
        }
        return -1;
}