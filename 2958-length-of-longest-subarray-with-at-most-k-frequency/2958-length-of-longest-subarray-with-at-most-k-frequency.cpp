class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        int j=0;
        int i=0;
        int max_size=INT_MIN;
        while(j<nums.size())
        {
            freq[nums[j]]++;
            while(freq[nums[j]]>k)
            {
                freq[nums[i]]--;
                i++;
            }
            int cur_size=j-i+1;
            max_size=max(cur_size,max_size);
            j++;
        }
        return max_size;
    }
};