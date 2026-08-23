class Solution {
    private boolean ispossible(int[] nums, long mid, int threshold)
    {
        long sum=0;
        for(int i=0;i<nums.length;i++)
        {
            if(nums[i]%mid==0)
            {
                sum+=(nums[i]/mid);
            }
            else
            {
                sum+=(nums[i]/mid)+1;
            }
        }
        if(sum<=threshold)
        {
            return true;
        }
        return false;
    }
    
    public int smallestDivisor(int[] nums, int threshold) {
        long ans=-1;
        long s=1;
        long maxi=Integer.MIN_VALUE;
        for(int i=0;i<nums.length;i++)
        {
            if(nums[i]>maxi)
            {
                maxi=nums[i];
            }
        }
        long e=maxi;
        while(s<=e)
        {
            long mid=s+(e-s)/2;
            if(ispossible(nums,mid,threshold))
            {
                ans=mid;
                e=mid-1;
            }
            else
            {
                s=mid+1;
            }
        }
        return (int)ans;
    }
}