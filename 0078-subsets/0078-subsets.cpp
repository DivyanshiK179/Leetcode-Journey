class Solution {
    private:
    void solve(vector<int> &nums, vector<int> &temp, vector<vector<int>> &output, int i)
    {
        if(i==nums.size())
        {
            output.push_back(temp);
            return;
        }
        solve(nums,temp,output,i+1);
        temp.push_back(nums[i]);
        solve(nums,temp,output,i+1);   
        temp.pop_back();    
    }


public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> output;
        vector<int> temp;
        solve(nums,temp,output,0);
        return output;
    }
};