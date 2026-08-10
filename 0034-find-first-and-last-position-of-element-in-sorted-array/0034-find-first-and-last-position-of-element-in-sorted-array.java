class Solution {
    private int lower_bound(int[] nums,int target,int size)
    {
        int s=0;
        int e=size-1;
        int ans=-1;
        while(s<=e)
        {
            int mid=(s+e)/2;
            if(nums[mid]==target)
            {
                ans=mid;
                e=mid-1;
            }
            else if(nums[mid]<target)
            {
                s=mid+1;
            }
            else
            {
                e=mid-1;
            }
        }
        return ans;  
    }  

    private int upper_bound(int[] nums,int target,int size)
    {
        int s=0;
        int e=size-1;
        int ans=-1;
        while(s<=e)
        {
            int mid=(s+e)/2;
            if(nums[mid]==target)
            {
                ans=mid;
                s=mid+1;;
            }
            else if(nums[mid]<target)
            {
                s=mid+1;
            }
            else
            {
                e=mid-1;
            }
        }
        return ans;  
    }
    public int[] searchRange(int[] nums, int target) {
        int res[]=new int[2];
        int size=nums.length;
        int l=lower_bound(nums,target,size);
        res[0]=l; 
        int u=upper_bound(nums,target,size); 
        res[1]=u;   
        return res;
    }
}