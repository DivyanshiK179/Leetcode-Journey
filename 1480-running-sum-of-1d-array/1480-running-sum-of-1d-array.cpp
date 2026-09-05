class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> res;
        int prefix_sum=0;
        for(int i=0;i<nums.size();i++)
        {
            prefix_sum+=nums[i];
            res.push_back(prefix_sum);
        }
        return res;
    }
};