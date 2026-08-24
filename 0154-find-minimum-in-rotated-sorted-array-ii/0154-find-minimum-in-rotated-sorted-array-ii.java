class Solution {
    public int findMin(int[] nums) {
        int s=0;
        int n=nums.length;
        int e=n-1;
        int minn=Integer.MAX_VALUE;
        while(s<=e)
        {
            int mid=s+(e-s)/2;
            if(nums[mid]<minn)
            {
                minn=nums[mid];
            }
            if(nums[mid]>nums[e])
            {
                s=mid+1;
            }
            else if(nums[mid]<nums[e])
            {
                e=mid-1;;
            }
            else
            {
                e--;
            }
        }
        return minn;
    }
}