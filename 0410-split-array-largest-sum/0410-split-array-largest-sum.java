class Solution {
    private boolean ispossible(int[] nums, long mid , int k)
    {
        long sum=0;
        int c=1;
        for(int i=0;i<nums.length;)
        {
            if(sum+nums[i]<=mid)
            {
                sum+=nums[i];
                i++;
            }  
            else
            {
                c++;
                sum=0;
            }      
            if(c>k)
            {
                return false;
            }
        }
        return true;
    }
    
    public int splitArray(int[] nums, int k)
    {
        long total=0;
        long maxi=0;
        for(int i=0;i<nums.length;i++)
        {
            if(nums[i]>maxi)
            {
                maxi=nums[i];
            }
            total+=nums[i];
        }
        long s=maxi;
        long e=total;
        long ans=e;
        while(s<=e)
        {
            long mid=(s+e)/2;
            if(ispossible(nums,mid,k))
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