class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int left=0;
        int right=0;
        vector<int> answer;
        vector<int> leftSum(nums.size());
        vector<int> rightSum(nums.size());
        for(int i=0;i<nums.size();i++)
        {
            leftSum[i]=left;
            left+=nums[i];
        }
        for(int i=nums.size()-1;i>=0;i--)
        {
            rightSum[i]=right;
            right+=nums[i];
        }
        for(int i=0;i<nums.size();i++)
        {
            answer.push_back(abs(leftSum[i]-rightSum[i]));
        }
        return answer;
    }
};