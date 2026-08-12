class Solution {
    public int maxSubarrayLength(int[] nums, int k) {
        Map<Integer,Integer> freq=new HashMap<>();
        int j=0;
        int i=0;
        int max_size=0;
        while(j<nums.length)
        {
            freq.put(nums[j],freq.getOrDefault(nums[j],0)+1);
            while(freq.get(nums[j])>k)
            {
                freq.put(nums[i],freq.get(nums[i])-1);
                i++;
            }
            int cur_size=j-i+1;
            max_size=Math.max(cur_size,max_size);
            j++;
        }
        return max_size;
    }
}