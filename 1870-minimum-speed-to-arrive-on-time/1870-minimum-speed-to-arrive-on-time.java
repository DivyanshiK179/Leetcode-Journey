class Solution {
    private boolean ispossible(int[] dist, long mid, double hour)
    {
        double h=0;
        int n=dist.length;
        for(int i=0;i<n-1;i++)
        {
            h+=(dist[i]+mid-1)/mid;
        }
        h+=(double)dist[n-1]/mid;
        if(h<=hour)
        {
            return true;
        }
        return false;
    }
    
    public int minSpeedOnTime(int[] dist, double hour) {
        long ans=-1;
        long s=1;
        long e=10_000_000;
        while(s<=e)
        {
            long mid=s+(e-s)/2;
            if(ispossible(dist,mid,hour))
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