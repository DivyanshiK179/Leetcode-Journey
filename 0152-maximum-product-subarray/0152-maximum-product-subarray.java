class Solution {
    public int maxProduct(int[] nums) {
        int max_prod=Integer.MIN_VALUE;
        for(int i=0;i<nums.length;i++)
        {
            int prod=1;
            for(int j=i;j<nums.length;j++)
            {
                prod*=nums[j];
                max_prod=Math.max(max_prod,prod);
            }
        }
        return max_prod;
    }
}