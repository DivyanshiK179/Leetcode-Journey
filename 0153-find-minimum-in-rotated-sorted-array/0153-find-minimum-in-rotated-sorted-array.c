int findMin(int* nums, int numsSize) {
        int s=0;
        int n=numsSize;
        int e=n-1;
        int minn=INT_MAX;
        while(s<=e)
        {
            int mid=(s+e)/2;
            if(nums[mid]<minn)
            {
                minn=nums[mid];
            }
            else if(nums[mid]>nums[e])
            {
                s=mid+1;
            }
            else
            {
                e=mid-1;
            }
        }
        return minn;
}