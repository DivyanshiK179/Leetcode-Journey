class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max1_ind=0;
        int max2=INT_MIN;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>nums[max1_ind])
            {
                max1_ind=i;
            }
        }
        for(int j=0;j<nums.size();j++)
        {
            if(nums[j]>max2 && j!=max1_ind)
            {
                max2=nums[j];
            }
        }
        return((nums[max1_ind]-1)*(max2-1));
    }
};