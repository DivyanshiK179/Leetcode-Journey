class Solution {
    public int minMoves(int[] nums) {
        int maxVal=nums[0];
        for(int i=1; i<nums.length; i++) 
        {
            if(nums[i]>maxVal) 
            {
                maxVal=nums[i];
            }
        }
        
        int moves=0;
        for(int x:nums) 
        {
            moves+=maxVal-x;
        }
        
        return moves;
    }
}