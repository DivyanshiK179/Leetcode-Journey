class Solution {
    public int missingMultiple(int[] nums, int k) {
        int[] freq=new int[10005];
        for(int i=0;i<nums.length;i++)
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
    }
}