class Solution {
    public List<Integer> findMissingElements(int[] nums) {
        List<Integer> res=new ArrayList<>();
        int minn=nums[0];
        int maxx=nums[0];
        for(int i:nums)
        {
            minn=Math.min(minn,i);
            maxx=Math.max(maxx,i);
        }
        for(int i=minn;i<maxx;i++)
        {
            if(!contains(nums,i))
            {
                res.add(i);
            }
        }
        return res;
    }
    private boolean contains(int[] nums,int target)
    {
        for(int i:nums)
        {
            if(i==target)
            {
                return true;
            }
        }
        return false;
    }
}

