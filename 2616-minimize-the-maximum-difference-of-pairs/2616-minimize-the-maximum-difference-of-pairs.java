class Solution {
    private boolean ispossible(int[] nums, int mid, int p)
    {
        int maxx=0;
        int pair=0;
        int i=0;
        while(i<nums.length-1)
        {
            if(Math.abs(nums[i+1]-nums[i])<=mid)
            {
                pair++;  
                i+=2;
            }
            else
            {
                i+=1;
            }   
        }
        if(pair>=p)
        {
            return true;
        }
        return false;
    }

    public int minimizeMax(int[] nums, int p) {
        Arrays.sort(nums);
        int ans=0;
        int s=0;
        int e=nums[nums.length-1]-nums[0];
        while(s<=e)
        {
            int mid=s+(e-s)/2;
            if(ispossible(nums,mid,p))
            {
                ans=mid;
                e=mid-1;
            }
            else
            {
                s=mid+1;
            }
        }
        return ans;
    }
}