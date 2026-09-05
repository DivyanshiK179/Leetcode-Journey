class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int prefix_sum=0;
        int total=0;
        for(int i=0;i<nums.size();i++)
        {
            total+=nums[i];
        }
        for(int i=0;i<nums.size();i++)
        {
            if(total-prefix_sum-nums[i]==prefix_sum)
            {
                return i;
            }
            prefix_sum+=nums[i];  
        }
        return -1;
    }
};