class Solution {
    private boolean ispossible(int[] ranks, long mid , int cars)
    {
        long c=0;
        for(int i=0;i<ranks.length;i++)
        {
            c+=Math.sqrt(mid/ranks[i]);
            if(c>=cars)
            {
                return true;
            }
        }
        return false;
    }
    public long repairCars(int[] ranks, int cars) {
        long s=1;
        long minn=Integer.MAX_VALUE;
        for(int i=0;i<ranks.length;i++)
        {
            if(ranks[i]<minn)
            {
                minn=ranks[i];
            }
        }
        long e=minn* (long) cars*cars;
        long ans=e;
        while(s<=e)
        {
            long mid=(s+e)/2;
            if(ispossible(ranks,mid,cars))
            {
                ans=mid;
                e=mid-1;
            }
            else
            {
                s=mid+1;
            }
        }
        return ans;
    }
}