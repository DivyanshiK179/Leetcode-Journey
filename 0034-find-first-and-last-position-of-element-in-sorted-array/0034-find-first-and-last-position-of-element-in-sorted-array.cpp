class Solution {
public:
    int lower_bound(const vector<int>& nums,int target,int size)
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

    int upper_bound(const vector<int>& nums,int target,int size)
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
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res;
        int size=nums.size();
        int l=lower_bound(nums,target,size);
        res.push_back(l); 
        int u=upper_bound(nums,target,size); 
        res.push_back(u);   
        return res;
    }
};