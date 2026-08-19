class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int i=0;
        int j=nums.size()-1;
        int k=nums.size()-1;
        vector<int> res(nums.size());
        while(i<=j)
        {
            if(abs(nums[i])<abs(nums[j]))
            {
                res[k]=nums[j]*nums[j];
                k--;
                j--;
            }
            else
            {
                res[k]=nums[i]*nums[i];
                k--;
                i++;
            }
        }
        return res;
    }
};