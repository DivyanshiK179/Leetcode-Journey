class Solution {
public:
    int findMin(vector<int>& nums) {
        int s=0;
        int n=nums.size();
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
};