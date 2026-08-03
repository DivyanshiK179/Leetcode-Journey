class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int cur_count=0;
        int max_count=0;
        for(int i:nums)
        {
            if(i==1)
            {
                cur_count+=1;
                max_count=max(cur_count,max_count);
            }
            else
            {
                cur_count=0;
            }
        }
        return max_count;
    }
};