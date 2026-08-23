class Solution {
    private boolean ispossible(int[] bloomDay, long mid, int m, int k)
    {
        int bouquet=0;
        int count=0;
        for(int i=0;i<bloomDay.length;i++)
        {
            if(bloomDay[i]<=mid)
            {
                count++;
                if(count==k)
                {
                    bouquet++;
                    count=0;
                }     
            }
            else
            {
                count=0;
            }
        }
        if(bouquet>=m)
        {
            return true;
        }
        return false;
    }

    public int minDays(int[] bloomDay, int m, int k) {
        if((long)m*k>bloomDay.length)
        {
            return -1;
        }
        long ans=-1;
        long s=1;
        long maxi=Integer.MAX_VALUE;
        for(int i=0;i<bloomDay.length;i++)
        {
            if(bloomDay[i]>maxi)
            {
                maxi=bloomDay[i];
            }
        }
        long e=maxi;
        while(s<=e)
        {
            long mid=(s+e)/2;
            if(ispossible(bloomDay,mid,m,k))
            {
                ans=mid;
                e=mid-1;
            }
            else
            {
                s=mid+1;
            }
        }
        return (int)ans;
    }
}