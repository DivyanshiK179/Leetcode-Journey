class Solution {
    private boolean ispossible(int[] time, long mid, int totalTrips)
    {
        long t=0;
        for(int i=0;i<time.length;i++)
        {
            t+=mid/time[i];
            if(t>=totalTrips)
            {
                return true;
            }
        }
        return false;
    }
    public long minimumTime(int[] time, int totalTrips) {
        long ans=-1;
        long s=1;
        long minn=0;
        for(int i=0;i<time.length;i++)
        {
            if(minn<time[i])
            {
                minn=time[i];
            }
        }
        long e=minn*totalTrips;
        while(s<=e)
        {
            long mid=(s+e)/2;
            if(ispossible(time,mid,totalTrips))
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