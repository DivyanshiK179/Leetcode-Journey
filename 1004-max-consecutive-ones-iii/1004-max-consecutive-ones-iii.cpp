class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i=0;
        int j=0;
        int max_win=-1;
        while(j<nums.size())
        {
            if(nums[j]==0)
            {
                k--;
            }
            while(k==-1)
            {
                if(nums[i]==0)
                {
                    k++;
                }
                i++;
            }
            int curr_win=j-i+1;
            max_win=max(max_win,curr_win);
            j++;
        }
        return max_win;
    }
};