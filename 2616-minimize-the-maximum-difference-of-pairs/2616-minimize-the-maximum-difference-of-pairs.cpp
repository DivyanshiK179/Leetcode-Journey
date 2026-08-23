class Solution {
    bool ispossible(vector<int> &nums, int mid, int p)
    {
        int maxx=0;
        int pair=0;
        int i=0;
        while(i<(int)nums.size()-1)
        {
            if(abs(nums[i+1]-nums[i])<=mid)
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
public:
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(),nums.end());
        long long ans=0;
        long long s=0;
        long long e=nums[nums.size()-1]-nums[0];
        while(s<=e)
        {
            long long mid=s+(e-s)/2;
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
};