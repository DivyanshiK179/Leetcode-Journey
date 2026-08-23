class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i=0;
        int j=0;
        int sum=0;
        int minn=INT_MAX;
        while(j<nums.size())
        {
            sum+=nums[j];
            while(sum>=target)
            {
                minn=min(j-i+1,minn);
                sum-=nums[i];
                i++;
            }
            j++;
        }
        return (minn==INT_MAX)?0:minn;
    }
};