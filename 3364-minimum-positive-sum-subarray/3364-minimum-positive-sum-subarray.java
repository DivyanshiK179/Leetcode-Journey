class Solution {
    public int minimumSumSubarray(List<Integer> nums, int l, int r) {
        int min_sum=-1;
        for(int len=l;len<=r;len++)
        {
            int i=0;
            int j=0;
            int cur_sum=0;
            while(j<nums.size())
            {
                cur_sum+=nums.get(j);
                if(j-i+1==len)
                {
                    if(cur_sum>0)
                    {
                        if(min_sum==-1||cur_sum<min_sum)
                        {
                            min_sum=cur_sum;
                        }
                    }
                    cur_sum-=nums.get(i);
                    i++;
                }
                j++;
            }
        }
        return min_sum;
    }
}