class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int total_xor=0;
        int has_nz=0;
        for(int i=0;i<nums.size();i++)
        {
            total_xor^=nums[i];
            if(nums[i]!=0)
            {
                has_nz=1;
            }
        }
        if(total_xor!=0)
        {
            return nums.size();
        }
        else if(has_nz)
        {
            return nums.size()-1;
        }
        return 0;
    }
};