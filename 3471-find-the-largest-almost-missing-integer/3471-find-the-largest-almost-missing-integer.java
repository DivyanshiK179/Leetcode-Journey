class Solution {
    public int largestInteger(int[] nums, int k) {
        int[] subarray_count=new int[51];
        int[] freq=new int[51];
        int i=0;
        int j=0;
        int maxi=-1;
        while(j<nums.length)
        {
            freq[nums[j]]++;
            if(j-i+1==k)
            {
                for(int c=0;c<51;c++)
                {
                    if(freq[c]>0)
                    {
                        subarray_count[c]++;
                    }
                }
                freq[nums[i]]--;
                i++;
            }
            j++;
        }
        for(int d=0;d<51;d++)
        {
            if(subarray_count[d]==1)
            {
                maxi=Math.max(maxi,d);
            }
        }
        return maxi;
    }
}