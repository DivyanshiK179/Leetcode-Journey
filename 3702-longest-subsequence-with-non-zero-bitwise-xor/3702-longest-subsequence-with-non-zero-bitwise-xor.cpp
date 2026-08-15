class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int total_xor=0;
        int has_nz=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            total_xor^=nums[i];
            if(nums[i]!=0)
            {
                has_nz=1;
            }
        }
        if(total_xor!=0)
        {
            return n;
        }
        else if(has_nz)
        {
            return n-1;
        }
        return 0;
    }
};