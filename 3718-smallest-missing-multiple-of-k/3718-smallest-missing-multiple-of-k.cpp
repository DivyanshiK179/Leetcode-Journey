class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        vector<int> freq(10005,0);
        for(int i=0;i<nums.size();i++)
        {
            freq[nums[i]]++;
        }
        for(int j=1; ;j++)
        {
            int prod=k*j;
            if(freq[prod]==0)
            {
                return prod;
            }
        }
        return -1;
    }
};