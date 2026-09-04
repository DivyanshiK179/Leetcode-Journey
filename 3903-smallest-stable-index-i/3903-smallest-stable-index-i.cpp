class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        for(int i=0;i<nums.size();i++)
        {
            int max=nums[0];
            for(int j=0;j<=i;j++)
            {
                if(nums[j]>max)
                {
                    max=nums[j];
                }
            }
            int min=nums[i];
            for(int k=i;k<nums.size();k++)
            {
                if(nums[k]<min)
                {
                    min=nums[k];
                }
            }
            if((max-min)<=k)
            {
                return i;
            }
        }
        return -1;
    }
};