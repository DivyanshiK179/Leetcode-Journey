class Solution {
    bool ispossible(vector<int> &nums, long long mid, int threshold)
    {
        long long sum=0;
        for(int i=0;i<nums.size();i++)
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

public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        long long ans=-1;
        long long s=1;
        long long maxi=INT_MIN;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>maxi)
            {
                maxi=nums[i];
            }
        }
        long long e=maxi;
        while(s<=e)
        {
            long long mid=s+(e-s)/2;
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
        return ans;
    }
};