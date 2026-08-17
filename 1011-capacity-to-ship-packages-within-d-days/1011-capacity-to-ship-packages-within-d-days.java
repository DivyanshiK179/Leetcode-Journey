class Solution {
    private boolean ispossible(int[] weights,int mid,int days)
    {
        int day=1;
        int ship_load=0;
        for(int i=0;i<weights.length;)
        {
            if(ship_load+weights[i]<=mid)
            {
                ship_load+=weights[i];
                i++;
            }
            else
            {
                day++;
                ship_load=0;
            }
            if(day>days)
            {
                return false;
            }
        }
        return true;
    }
    public int shipWithinDays(int[] weights, int days) {
        int ans=0;
        int total=0;
        for(int i=0;i<weights.length;i++)
        {
            total+=weights[i];
        }
        int s=1;
        int e=total;
        while(s<=e)
        {
            int mid=(s+e)/2;
            if(ispossible(weights,mid,days))
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