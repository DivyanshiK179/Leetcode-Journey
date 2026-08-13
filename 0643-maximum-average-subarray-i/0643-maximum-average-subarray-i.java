class Solution {
    public double findMaxAverage(int[] nums, int k) {
        int i=0;
        int j=0;
        double sum=0;
        double maxi=Integer.MIN_VALUE;
        while(j<nums.length)
        {
            sum+=nums[j];
            if(j-i+1<k)
            {
                j++;
            }
            else if(j-i+1==k)
            {
                maxi=Math.max(sum,maxi);
                sum-=nums[i];
                i++;
                j++;
            }
        }
        return maxi/k;
    }
}