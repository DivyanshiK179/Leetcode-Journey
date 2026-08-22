class Solution {
    bool ispossible(vector<int>& nums, int mid , int k)
    {
        long long sum=0;
        int c=1;
        for(int i=0;i<nums.size();)
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
    
public:
    int splitArray(vector<int>& nums, int k) {
        long long total=0;
        long long maxi=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>maxi)
            {
                maxi=nums[i];
            }
            total+=nums[i];
        }
        long long s=maxi;
        long long e=total;
        long long ans=e;
        while(s<=e)
        {
            long long mid=(s+e)/2;
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
        return ans;
    }
};