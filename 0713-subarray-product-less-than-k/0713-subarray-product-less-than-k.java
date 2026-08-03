class Solution {
    public int numSubarrayProductLessThanK(int[] nums, int k) {
        int i=0;
        int j=0;
        long prod=1;
        int count=0;
        while(j<nums.length)
        {
            prod*=nums[j];
            while(prod>=k && i<=j)
            {
                prod/=nums[i];
                i++;
            }
            count+=(j-i+1);
            j++;
        }
        return count;


    }
}